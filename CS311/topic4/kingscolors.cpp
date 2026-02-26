/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)(x).size()

typedef long long ll;
const ll mod = 1e9 + 7;

ll power(ll a, ll b, ll m) {
    ll res = 1;
    for (a %= m; b > 0; b >>= 1, a = a * a % m)
        if (b & 1) res = res * a % m;
    return res;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> f(k + 1, 1), inv(k + 1, 1);

    for(int i = 1; i <= k; ++i) {
        f[i] = f[i-1] * i % mod;
        inv[i] = power(f[i], mod-2, mod);
    }

    ll ans = 0;
    for(int i = 2; i <= k; ++i) {
        ll c = f[k] * inv[i] % mod * inv[k-i] % mod;
        ll ways = c * i % mod * power(i-1, n-1, mod) % mod;

        if ((k - i) % 2) {
            ans = (ans - ways + mod) % mod;
        } else {
            ans = (ans + ways) % mod;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    solve();
}