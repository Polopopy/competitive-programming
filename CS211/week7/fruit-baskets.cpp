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

const int maxn = 4e5+5;
const int inf = 1e9+2;
const int mod = 2e9;

int n;
vector<ll> dp(maxn);

void solve() {
    cin >> n;
    dp[0] = 1;
    ll ans = 0;
    F0R(i, n) {
        ll x; cin >> x;
        ROF(j, 4e5, x) {
            if(dp[j-x] > 0) {
                dp[j] += dp[j-x];
            }
        }
    }

    FOR(i, 200, 4e5) {
        if(dp[i] > 0) ans += i*dp[i];
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