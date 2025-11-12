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
    int n; 
    while(cin >> n && n != 0) {
        vector<int> x(n+1);
        vector<pair<int, vector<int>>> dp(n+1);
        FOR(i, 1, n+1) cin >> x[i];

        dp[1].f = 1;
        dp[1].s.pb(x[1]);

        FOR(i, 2, n+1) {
            int bi = 0;
            F0R(j, i) {
                if(dp[j].s.empty() || x[i] > dp[j].s.back()) {
                    if(dp[i].f < (dp[j].f+1)) {
                        bi = j;
                        dp[i].f = dp[j].f+1;
                    } else if(dp[i].f == (dp[j].f+1)) {
                        if(dp[bi].s.back() > dp[j].s.back()) {
                            bi = j;
                        }
                    }
                }
            }
            dp[i].s = dp[bi].s;
            dp[i].s.pb(x[i]);
        }

        int ans = 0, blorp = 0;
        FOR(i, 1, n+1) {
            if(dp[i].f >= ans) {
                ans = dp[i].f;
                blorp = i;
            }
        }

        cout << dp[blorp].f;
        trav(x, dp[blorp].s) cout << ' ' << x;
        cout << endl;
    }
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