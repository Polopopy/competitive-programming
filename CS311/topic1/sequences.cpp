/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9+7;

// custom power function because C++ built-in power uses doubles
// also used to mod while computing
ll power(ll a, ll b, ll m) {
    ll res = 1;
    for (a %= m; b > 0; b >>= 1, a = a * a % m)
        if (b & 1) res = res * a % m;
    return res;
}

void solve() {
    string s; cin >> s;
    ll ans = 0;
    ll os = 0, qs = 0;

    // compute total number of question marks
    ll tq = 0;
    for(int i = 0; i < s.size(); ++i) if(s[i] == '?') tq++;

    for(ll i = 0; i < s.size(); ++i) {
        // count # of ones we've passed
        if(s[i] == '1') os++;
        
        // for any 0, the number of inversions to properly place it is equal to the number of 
        // ones before it which is calculated as the sum of the number of ones up to
        // the # of ones + i multiplied by # of question marks choose i
        // where i ranges from 0 to the # of question marks

        // this formula has a closed form of (2 * # of ones + # of question marks) * 2^(# of question marks - 1)
        // we then multiply it by 2^(# of question marks remaining) to account for the later question marks
        if(s[i] == '0') {
            ll tmp = os;
            if(qs > 0) tmp = (2*os + qs) * power(2, qs-1, mod);
            tmp %= mod;
            ans += tmp * power(2, tq-qs, mod);
            ans %= mod;
        }
        // question marks are almost the same as 0's, except we increment the number of question marks
        // this also impacts how many questions marks remain for the purposes of our calculations
        if(s[i] == '?') {
            ll tmp = os;
            if(qs > 0) tmp = (2*os + qs) * power(2, qs-1, mod);
            tmp %= mod;
            qs++;
            ans += tmp * power(2, tq-qs, mod);
            ans %= mod;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}