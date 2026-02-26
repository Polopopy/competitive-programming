/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

typedef long long ll;

ll power(ll a, ll b, ll m) {
    ll res = 1;
    for (a %= m; b > 0; b >>= 1, a = a * a % m)
        if (b & 1) res = res * a % m;
    return res;
}

void solve() {
    ll n; cin >> n;
    // first digit can't be a 9 OR a 0
    ll ans = 8;
    // all remaining digits can be 0 through 8 inclusive
    ans *= power(9, n-1, mod);
    cout << ans%mod << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while(T--) solve();
}