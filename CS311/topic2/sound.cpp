/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, c; cin >> n >> m >> c;
    deque<int> a, b;
    vector<int> lvls(n);
    for(auto& x : lvls) cin >> x;
    vector<int> ans;

    for(int i = 0; i < n; ++i) {
        int tmp = 0, s = 0;
        
        while(!a.empty() && lvls[a.back()] > lvls[i]) a.pop_back();
        while(!b.empty() && lvls[b.back()] < lvls[i]) b.pop_back();

        if(!a.empty() && i-a.front() >= m) a.pop_front();
        if(!b.empty() && i-b.front() >= m) b.pop_front();

        a.push_back(i);
        b.push_back(i);

        if(i+1 < m) continue;
        if(!a.empty() && !b.empty() && lvls[b.front()]-lvls[a.front()] <= c) {
            ans.push_back(i-m+2);
        }
        
    }

    if(ans.size() == 0) cout << "NONE" << endl;
    else for(auto& x : ans) cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}