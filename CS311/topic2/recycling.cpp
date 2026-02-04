/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<ll> days(n+2);
    for(int i = 1; i <= n; ++i) cin >> days[i];

    ll s = 1, e = 1, r = 0;
    deque<int> dq;

    for(int i = 0; i <= n+1; ++i) {
        while(!dq.empty() && days[dq.back()] > days[i]) {
            ll h = dq.back();
            dq.pop_back();

            ll a = (dq.empty()? 0:dq.back());
            ll vol = days[h] * (i-a-1);

            if(vol > r) {
                r = vol;
                s = a+1;
                e = i-1;
            } else if(vol == r && a+1 < s) {
                s = a+1;
                e = i-1;
            }
        }
        dq.push_back(i);
    }

    cout << s << ' ' << e << ' ' << r << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}