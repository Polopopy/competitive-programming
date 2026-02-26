/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

ll power(ll a, ll b, ll m) {
    ll res = 1;
    for (a %= m; b > 0; b >>= 1, a = a * a % m)
        if (b & 1) res = res * a % m;
    return res;
}

ll choose(ll n, ll k, vector<ll>& f) {
    if (k < 0 || k > n) return 0;
    ll num = f[n];
    ll den = f[k] * f[n-k] % mod;
    return num * power(den, mod-2, mod) % mod;
}

void solve() {
    int n, x, y; cin >> n >> x >> y;
    vector<ll> f(n + 1, 1);

    for (int i = 1; i <= n; ++i) f[i] = f[i-1]*i % mod;

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ll dx = n - i*x;
        ll dy = n - i*y;
        ll wx = choose(dx+i-1, i-1, f);
        ll wy = choose(dy+i-1, i-1, f);

        ans = (ans + wx * wy) % mod;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}