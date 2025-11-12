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

vector<vector<int>> dp(21, vector<int>(5005));

void solve() {
   int n, m; cin >> n >> m;

   FOR(i, 1, m+1) {
      FOR(j, 1, n+1) {
         dp[i][j] = dp[i-1][j-1] + dp[i][j-1] + 1;
      }
   }

   int ans = 0, lo = 0, hi = 0;

   FOR(i, 1, n+1) {
      if(dp[m][i] >= n) {
         ans = i;
         lo = n - dp[m][i-1];
         hi = dp[m-1][i-1]+1;
         break;
      }
   }

   cout << ans << ' ';
   if(lo == hi) cout << lo << endl;
   else cout << lo << '-' << hi << endl;
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