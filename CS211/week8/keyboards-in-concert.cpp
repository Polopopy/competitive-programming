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

const int maxn = 1005;
const int inf = 1e9+2;
const int mod = 2e9;

vector<vector<int>> dp(maxn, vector<int>(maxn, inf));
vector<set<int>> instr(maxn);
vector<int> song(maxn);

void solve() {
    int n, m; cin >> n >> m;

    FOR(i, 1, n+1) {
        int x; cin >> x;
        dp[i][0] = 0;
        F0R(j, x) {
            int a; cin >> a;
            instr[i].ins(a);
        }
    }

    FOR(i, 1, m+1) cin >> song[i];

    FOR(j, 1, m+1) {
        FOR(i, 1, n+1) {
            if(instr[i].find(song[j]) == instr[i].end()) {
                dp[i][j] = -1;
                continue;
            }

            if(dp[i][j-1] != -1) dp[i][j] = dp[i][j-1];

            FOR(k, 1, n+1) {
                if(k == i || dp[k][j-1] == -1) continue;
                dp[i][j] = min(dp[k][j-1]+1, dp[i][j]);
            }
        }
    }

    int ans = inf;
    FOR(i, 1, n+1) if(dp[i][m] != -1) ans = min(dp[i][m], ans);
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