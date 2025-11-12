#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)
#define R0F(i, a) ROF(i, a, 0)
#define trav(a,x) for (auto& a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define ins insert
#define endl '\n'

const int maxn = 1e5+5;
const int inf = 1e9+2;
const int mod = 2e9;

int r, c, tr, tc;

// dir 1 is right, 2-4 ccw

void sim(int cr, int cc, int dir, vector<vector<int>>& grid, vector<vector<vector<bool>>>& v) {
    if(v[cr][cc][dir]) return;
    v[cr][cc][dir] = true;
    if(cr == tr && cc == tc) return;

    if(dir == 1) {
        if(cr-1 >= 0 && grid[cr-1][cc] != 1) {
            sim(cr-1, cc, dir+1, grid, v);
        } else if(cc+1 < c && grid[cr][cc+1] != 1) {
            sim(cr, cc+1, dir, grid, v);
        } else {
            sim(cr, cc, 4, grid, v);
        }
    } else if(dir == 2) {
        if(cc-1 >= 0 && grid[cr][cc-1] != 1) {
            sim(cr, cc-1, dir+1, grid, v);
        } else if(cr-1 >= 0 && grid[cr-1][cc] != 1) {
            sim(cr-1, cc, dir, grid, v);
        } else {
            sim(cr, cc, dir-1, grid, v);
        }
    } else if(dir == 3) {
        if(cr+1 < r && grid[cr+1][cc] != 1) {
            sim(cr+1, cc, dir+1, grid, v);
        } else if(cc-1 >= 0 && grid[cr][cc-1] != 1) {
            sim(cr, cc-1, dir, grid, v);
        } else {
            sim(cr, cc, dir-1, grid, v);
        }
    } else {
        if(cc+1 < c && grid[cr][cc+1] != 1) {
            sim(cr, cc+1, 1, grid, v);
        } else if(cr+1 < r && grid[cr+1][cc] != 1) {
            sim(cr+1, cc, dir, grid, v);
        } else {
            sim(cr, cc, dir-1, grid, v);
        }
    }
}

void solve() {
    int r1, c1;
    cin >> r >> c >> r1 >> c1 >> tr >> tc;
    r1--;
    c1--;
    tr--;
    tc--;
    vector<vector<int>> grid(r, vector<int>(c));
    vector<vector<vector<bool>>> visited(r, vector<vector<bool>>(c, vector<bool>(5)));

    F0R(i, r) {
        string s; cin >> s;
        F0R(j, c) grid[i][j] = s[j]-'0';
    }

    sim(r1, c1, 1, grid, visited);
    
    int ans = 0;
    FOR(i, 1, 5) {
        if(visited[tr][tc][i]) {
            ans = 1;
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    // freopen("fname.in", "r", stdin);
    // freopen("fname.out", "w", stdout);

    // int T;
    // cin >> T;
    // while(T--) {
    //    solve();
    // }

    solve();

    return 0;
}