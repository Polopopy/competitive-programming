/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll power(ll a, ll b, ll m) {
    ll res = 1;
    for (a %= m; b > 0; b >>= 1, a = a * a % m)
        if (b & 1) res = res * a % m;
    return res;
}

void solve() {
    int n, v1, v2, w;
    cin >> n >> v1 >> v2 >> w;
    int rem = n-v1-v2;
    int req = (n/2+1)-v1;
    
    ll tot = power(2, rem, LLONG_MAX);
    ll win = 0;

    if(req <= 0) {
        win = tot;
    } else if(req <= rem) {
        for(int i = req; i <= rem; ++i) {
            ll c = 1;
            int r = (i > rem/2)? rem-i:i;
            for(int j = 1; j <= r; ++j) {
                c = c * (rem-j+1) / j;
            }
            win += c;
        }
    }
    
    if(win*100 > w*tot) {
        cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
    } else if(win == 0) {
        cout << "RECOUNT!" << endl;
    } else {
        cout << "PATIENCE, EVERYONE!" << endl;
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