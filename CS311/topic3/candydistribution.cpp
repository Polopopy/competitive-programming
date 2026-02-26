/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Disclaimer: I had to look up how to implement this
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, x2;
    ll d = exgcd(b, a%b, x1, x2);
    x = x2;
    y = x1 - x2*(a/b);
    return d;
}

void solve() {
    ll k, c;
    cin >> k >> c;
    
    if (k == 1) {
        ll num = (c == 1 ? 2 : 1);
        cout << num << endl;
        return;
    }

    ll x, y;
    ll g = exgcd(c, k, x, y);

    if (g != 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    x = (x % k + k) % k;
    if (x == 0) x = k;

    if (x * c <= k) {
        x += k;
    }
    if (x > 1000000000LL) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << x << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}