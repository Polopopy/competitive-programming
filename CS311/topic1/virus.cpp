/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int l = 0, r = 0;

    // find first difference from left
    while(l < n && l < m && a[l] == b[l]) l++;
    // find first difference from the right
    while(r < n-l && r < m-l && a[n-1-r] == b[m-1-r]) r++;

    cout << m-r-l << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}