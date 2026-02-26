/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> cols(m);
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        for(int j = 0; j < m; ++j) {
            if(s[j] == '.') {
                cols[j]++;
            } else {
                cols[j] = 0;
            }
        }

        stack<int> st;
        
        for(int j = 0; j <= m; ++j) {
            int curr = (j == m) ? 0 : cols[j];
            while(!st.empty() && curr < cols[st.top()]) {
                int h = cols[st.top()];
                st.pop();
                
                int w = st.empty() ? j : (j - st.top() - 1);
                
                if (h > 0) {
                    ans = max(ans, 2*(h+w));
                }
            }
            st.push(j);
        }
    }

    if (ans > 0) {
        cout << ans-1 << endl;
    } else {
        cout << 0 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
    return 0;
}