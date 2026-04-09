/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    getline(cin, s);
    int n = (int)s.size();
    string tmp = "";
    // for each substring from 0 to i
    for(int i = 0; i < n; ++i) {
        tmp += s[i];
        int mod = (int)tmp.size();
        bool works = true;
        // loop through the entire string to check if it matches
        for(int j = 0; j < n; ++j) {
            if(s[j] != tmp[j % mod]) {
                works = false;
                break;
            }
        }
        // if it matches we are done
        if(works) {
            cout << mod << endl;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int T; cin >> T;
    cin.ignore();
    while(T--) solve();
}