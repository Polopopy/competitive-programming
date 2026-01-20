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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    F0R(i, n) {
        string s;
        cin >> s;
        F0R(j, m) {
            grid[i][j] = s[j]-'0';
        }
    }

    int q; cin >> q;

    vector<int> dr={-1,-1,0,1,1,1,0,-1},
                dc={0,1,1,1,0,-1,-1,-1};
    F0R(rep, q) {
        vector<vector<int>> dp(n, vector<int>(m, inf));
        int sr, sc, fr, fc;
        cin >> sr >> sc >> fr >> fc;
        sr--;
        sc--;
        fr--;
        fc--;
        
        dp[sr][sc] = 0;

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;

        pq.emplace(0, mp(sr, sc));

        while(!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            int r = x.s.f;
            int c = x.s.s;
            int w = x.f;

            if(w != dp[r][c]) continue;

            F0R(i, 8) {
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                int nw = w;
                if(i != grid[r][c]) nw++;
                if(nw < dp[nr][nc]) {
                    dp[nr][nc] = nw;
                    pq.emplace(nw, mp(nr, nc));
                }
            }
        }
        cout << dp[fr][fc] << endl;
    }
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