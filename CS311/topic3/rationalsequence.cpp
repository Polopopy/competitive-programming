/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int cn; cin >> cn;
    int a, b;
    cin >> a;
    cin.ignore();
    cin >> b;

    cout << cn << ' ';
    if(a < b) { // left node
        int p = a;
        int q = b-a;
        p += q;
        cout << p << '/' << q << endl;
    } else if(b < a) { // right node
        if(b == 1) { // rightmost right sub
            int p = b;
            int q = a;
            q += p;
            cout << p << '/' << q << endl;
        } else { // right
            int p = b;
            int q = b-a%b;
            q += a/b*p;
            cout << p << '/' << q << endl;
        }
        
    } else { // root node?
        cout << "1/2" << endl;
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