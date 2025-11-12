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

const int maxn = 1e3+5;
const int inf = 1e9+2;
const int mod = 2e9;

void solve() {
    int n; cin >> n;
    vector<int> dp(maxn, inf);
    vector<vector<int>> prev(n+1, vector<int>(maxn));
    vector<vector<char>> mvs(n+1, vector<char>(maxn));

    dp[0] = 0;
    int sum = 0;

    FOR(i, 1, n+1) {
        int x; cin >> x;
        sum += x;

        vector<int> d(maxn, inf);

        F0R(j, 1001) {
            if(dp[j] != inf) {
                if(j+x <= 1000) {
                    int tmp = max(dp[j], j+x);
                    if(tmp < d[j+x] || (tmp == d[j+x] && mvs[i][j+x] != 'D')) {
                        d[j+x] = tmp;
                        prev[i][j+x] = j;
                        mvs[i][j+x] = 'U';
                    }
                }

                if(j-x >= 0) {
                    int tmp = dp[j];
                    if(tmp < d[j-x] || (tmp == d[j-x] && mvs[i][j-x] != 'D')) {
                        d[j-x] = tmp;
                        prev[i][j-x] = j;
                        mvs[i][j-x] = 'D';
                    }
                }
            }
        }
        dp.swap(d);
    }
    if(dp[0] == inf) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        string ans = "";
        int pos = 0;
        ROF(i, n, 1) {
            ans += mvs[i][pos];
            pos = prev[i][pos];
        }
        reverse(all(ans));
        cout << ans << endl;
    }
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