#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> pos(n, vector<int>(k));
    vector<string> dih;
    dih.reserve(n);

    // precompute for easy letter comparison
    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        for(int j = 0; j < (int)s.size(); ++j) {
            pos[i][s[j]-'A'] = j;
        }
        dih.push_back(s);
    }
    // construct graph for each letter pair
    vector<vector<int>> adj(k);
    vector<int> deg(k);
    for(int a = 0; a < k; ++a) {
        for(int b = 0; b < k; ++b) {
            if(a == b) continue;
            bool good = true;
            for(int i = 0; i < n; ++i) {
                if(pos[i][a] > pos[i][b]) {
                    good = false;
                    break;
                }
            }
            if(good) {
                // cout << char(a+'A') << ' ' << char(b+'A') << endl;
                adj[a].push_back(b);
                deg[b]++;
            }
        }
    }

    // topo sort with each starting pt
    deque<int> td;
    vector<int> dp(k);
    int ans = 1;
    for(int i = 0; i < k; ++i) {
        if(deg[i] == 0) {
            td.push_back(i);
            dp[i] = 1;
        }
    }

    while(!td.empty()) {
        int curr = td.front();
        td.pop_front();
        ans = max(ans, dp[curr]);
        for(auto nx : adj[curr]) {
            deg[nx]--;
            if(deg[nx] == 0) td.push_back(nx);
            dp[nx] = max(dp[nx], dp[curr]+1);
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}