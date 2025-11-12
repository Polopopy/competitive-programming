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

void solve() {
    int n; cin >> n;
    vector<vector<int>> filled(n, vector<int>(n)), x(n, vector<int>(n));
    
    F0R(i, n) {
        string s; cin >> s;
        F0R(j, n) x[i][j] = s[j]-'0';
    }

    vector<int> ans(7);
    int sum = 0;

    deque<pair<int, int>> fm;
    fm.pb({0, 0});

    while(!fm.empty()) {
        auto c = fm.back();
        fm.pop_back();

        filled[c.f][c.s] = 1;

        vector<int> dr = {1,0,-1,0}, dc = {0,1,0,-1};
        F0R(a, 4) {
            pair<int, int> nx = {c.f+dr[a], c.s+dc[a]};
            if(nx.f < 0 || nx.s < 0 || nx.f >= n || nx.s >= n || filled[nx.f][nx.s] || x[nx.f][nx.s] != x[0][0]) {
                continue;
            }
            fm.pb(nx);
        }
    }

    while(true) {
        vector<vector<pair<int, int>>> tmp(7);
        FOR(cv, 1, 7) {
            pair<int, int> start = {0, 0};
            deque<pair<int, int>> td;
            td.pb(start);
            vector<vector<int>> vis(n, vector<int>(n));
            
            while(!td.empty()) {
                auto c = td.back();
                td.pop_back();
                if(c.f < 0 || c.s < 0 || c.f >= n || c.s >= n || vis[c.f][c.s] != 0 || filled[c.f][c.s] == 0 && x[c.f][c.s] != cv) continue;

                vis[c.f][c.s] = 1;
                
                if(filled[c.f][c.s] == 0 && x[c.f][c.s] == cv) {
                    tmp[cv].pb({c});
                }

                vector<int> dr = {1,0,-1,0}, dc = {0,1,0,-1};
                F0R(a, 4) {
                    pair<int, int> nx = {c.f+dr[a], c.s+dc[a]};
                    if(nx.f < 0 || nx.s < 0 || nx.f >= n || nx.s >= n || vis[nx.f][nx.s] != 0 || filled[nx.f][nx.s] == 0 && x[nx.f][nx.s] != cv) {
                        continue;
                    }
                    td.pb(nx);
                }
            }
        }

        int nx = -1, bs = 0;
        FOR(i, 1, 7) {
            if(sz(tmp[i]) > bs) {
                bs = sz(tmp[i]);
                nx = i;
            }
        }

        if(nx == -1) break;
        
        trav(x, tmp[nx]) {
            filled[x.f][x.s] = 1;
        }
        
        ans[nx]++;
        sum++;
    }

    cout << sum << endl;
    FOR(i, 1, 7) cout << ans[i] << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    // freopen("filename.in", "r", stdin);
    // freopen("filename.out", "w", stdout);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }

    // solve();
}