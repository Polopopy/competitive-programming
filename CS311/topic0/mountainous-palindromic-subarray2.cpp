/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve() {
    // read inputs
    int n; cin >> n;
    int ans = 0;
    vector<int> x(n);
    for(int i = 0; i < n; ++i) cin >> x[i];

    // for each possible peak (non-ends)
    for(int i = 1; i < n-1; ++i) {
        int tmp = 1;
        bool valid = true;
        int a = i-1, b = i+1;
        // scan left and right
        while(a >= 0 && b < n) {
            // if it is palindromic AND strictly decreasing from the current peak, update local answer
            if(x[a] == x[b] && x[a] < x[a+1] && x[b] < x[b-1]) {
                tmp += 2;
            } else {
                valid = false;
                break;
            }
            a--;
            b++;
        }
        // if valid and better than global answer, update global answer
        if(tmp >= 3) {
            ans = max(ans, tmp);
        }
    }

    cout << (ans==0? -1:ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}