/*

Author: Ray Han
It is ok to share my code anonymously for educational purposes

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s; 
    cin >> s;

    // initialize answer as 50 z's (really "big" string)
    string answer = string(50, 'z');
    int n = s.length();

    // try every two places to split
    // note i starts at 1 because we must split EXACTLY twice
    for(int i = 1; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            // get the split strings
            string a = s.substr(0, i);
            string b = s.substr(i, (j-i));
            string c = s.substr(j, (n-j));

            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());

            // compare to answer
            answer = min(answer, a+b+c);
        }
    }
    cout << answer << '\n';

	return 0;
}