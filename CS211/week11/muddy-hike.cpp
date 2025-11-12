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
const int inf = 2e9+2;
const int mod = 1e7+6;

vector<int> dr = {-1,0,1,0}, dc = {0,1,0,-1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m)), d(n, vector<int>(m));
    F0R(i, n) {
        F0R(j, m) {
            cin >> grid[i][j];
            d[i][j] = inf;
        }
        d[i][0] = grid[i][0];
    }

    priority_queue<pair<int, pair<int, int>>, 
                   vector<pair<int, pair<int, int>>>, 
                   greater<pair<int, pair<int, int>>>> pq;
    F0R(start, n) {
        pq.emplace(grid[start][0], mp(start, 0));
    }
    while(!pq.empty()) {
        auto bla = pq.top();
        pq.pop();
        int cd = bla.f;
        int r = bla.s.f;
        int c = bla.s.s;

        if(cd != d[r][c]) continue;

        F0R(i, 4) {
            int nr = r+dr[i], nc = c+dc[i];
            if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            int nd = max(cd, grid[nr][nc]);
            if(nd < d[nr][nc]) {
                d[nr][nc] = nd;
                pq.emplace(nd, mp(nr, nc));
            }
        }
    }
    
    int ans = inf;
    F0R(i, n) {
        ans = min(d[i][m-1], ans);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    // freopen("filename.in", "r", stdin);
    // freopen("filename.out", "w", stdout);

    // int T;
    // cin >> T;
    // while(T--) {
    //     solve();
    // }

    solve();
}