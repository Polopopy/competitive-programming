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
    int n, p; cin >> p >> n;
    vector<int> b(n+5), dp(1e5+5, inf);
    F0R(i, n) cin >> b[i];
    //dp[i] = min num of coins to make i

    dp[0] = 0;

    F0R(i, n) {
        ROF(j, 1e5, b[i]) {
            if(dp[j-b[i]] != inf) dp[j] = min(dp[j], dp[j-b[i]]+1);
        }
    }

    FOR(i, p, 1e5) {
        if(dp[i] != inf) {
            cout << i << ' ' << dp[i] << endl;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    // freopen("fname.in", "r", stdin);
    // freopen("fname.out", "w", stdout);

    int T;
    cin >> T;
    while(T--) {
       solve();
    }

    // solve();

    return 0;
}