/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    // read input
    string s; cin >> s;
    ll ans = 0;
    // maintain a set of unique characters seen
    vector<set<char>> seen(26);

    for(char c : s) {
        // increment the answer by the number of unique characters between this occurrence of the character
        //  and update trackers
        int x = c-'a';
        ans += seen[x].size();
        seen[x].clear();
        for(int i = 0; i < 26; ++i) {
            if(i != x) {
                seen[i].insert(x);
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    // freopen("filename.in", "r", stdin);
    // freopen("filename.out", "w", stdout);

    // int T;
    // cin >> T;
    // while(T--) {
    //     solve();
    // }

    solve();
}