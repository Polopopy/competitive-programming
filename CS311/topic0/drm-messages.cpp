/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve() {

    // read inputs
    string s; cin >> s;
    int n = s.length();
    
    // split input string in half
    string a = s.substr(0, n/2), b = s.substr(n/2, n/2);
    int x = 0, y = 0;
    for(char c : a) x += c-'A';
    for(char c : b) y += c-'A';

    // process both halves separately
    for(int i = 0; i < n/2; ++i) {
        int tmp = a[i]+x-'A';
        tmp %= 26;
        tmp += 'A';
        a[i] = char(tmp);
    }

    for(int i = 0; i < n/2; ++i) {
        int tmp = b[i]+y-'A';
        tmp %= 26;
        tmp += 'A';
        b[i] = char(tmp);
    }

    // build final string
    for(int i = 0; i < n/2; ++i) {
        int tmp = a[i]-'A'+b[i]-'A';
        tmp %= 26;
        tmp += 'A';
        a[i] = char(tmp);
    }

    cout << a << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}