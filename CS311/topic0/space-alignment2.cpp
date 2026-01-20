/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int lvl = 0, ans = -1;

    // td is a map that contains a set of equations/constraints at each level
    map<int, set<pair<int, int>>> td;

    // build/save constraints at each level
    bool done = false;
    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        int a = 0, b = 0;
        for(auto& c : s) {
            if(c == '{') {
                if(lvl > 0) td[lvl].insert(make_pair(a, b));
                lvl++;
            } else if(c == '}') {
                lvl--;
                if(lvl > 0) td[lvl].insert(make_pair(a, b));
            } else if(c == 's') {
                a++;
            } else if(c == 't') {
                b++;
            }
        }
    }

    // try all possible replacements for t
    for(int i = 1; i < 1001; ++i) {
        int tmp = -1;
        bool valid  = true;
        for(auto& x : td) {
            for(auto& curr : x.second) {
                int res = curr.first + curr.second*i;
                if(tmp == -1) {
                    tmp = res;
                } else {
                    if(tmp*x.first != res) {
                        valid = false;
                        break;
                    }
                }
            }
            if(!valid) break;
        }
        if(valid) {
            ans = i;
            break;
        }
    }
    
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}