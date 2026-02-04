/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    int ans = 1;
    // simulate tolls
    while(n > 0) {
        // will need to cross this toll ceil(n/k) times
        int rem = (n+k-1)/k;
        ans++;
        n -= rem;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}