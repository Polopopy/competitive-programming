/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int l = 0, r = n-1;
    int ans = 0;
    // BSTA on the length of the string
    while(l <= r) {
        // m is the size we are checking
        int m = l + (r-l)/2;
        if(m == 0) {
            l = m + 1;
            continue;
        }
        unordered_set<ull> seen;
        ull hash = 0;
        ull p = 1;

        // first window
        for(int i = 0; i < m; ++i) {
            p *= 13;
            hash = hash * 13 + s[i];
        }
        seen.insert(hash);

        // sliding window
        bool dupe = false;
        for(int i = m; i < n; ++i) {
            // custom polynomial hash
            hash = hash * 13 + s[i];
            hash -= s[i-m] * p;
            // if we've seen it before, we found a valid answer
            if(seen.count(hash)) {
                dupe = true;
                break;
            }
            seen.insert(hash);
        }
        // update binary search based on whether we found a valid answer
        if(dupe) {
            ans = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}