/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// 1 = none, 0 = left, 2 = right

// we can precompute the minimum cost incurred when we close k galleries with a 3d dp
int dfs(int &n, int r, int k, int prev, vector<vector<int>> &gallery, vector<vector<vector<int>>>& dp) {
    if(k == 0) return 0;
    if(r >= n) return 1e9;
    if(dp[r][k][prev] != -1) return dp[r][k][prev];

    // we can close no rooms on our row and move on
    int curr = dfs(n, r+1, k, 1, gallery, dp);
    // we can close the right room IF we did not just close the left room
    if(prev >= 1) curr = min(curr, dfs(n, r+1, k-1, 2, gallery, dp) + gallery[r][1]);
    // we can close the left room IF we did not just close the right room
    if(prev <= 1) curr = min(curr, dfs(n, r+1, k-1, 0, gallery, dp) + gallery[r][0]);

    // track in dp and return min cost
    dp[r][k][prev] = curr;
    return curr;
}

void solve() {
    int n, k; cin >> n >> k;
    int sum = 0;
    vector<vector<int>> gallery(n, vector<int>(2));
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(3, -1)));

    // build gallery and track total value of the entire gallery
    for(int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        sum += (a+b);
        gallery[i][0] = a;
        gallery[i][1] = b;
    }

    // answer is the total sum of value - the minimum cost to satisfy closing requirements
    cout << sum-dfs(n, 0, k, 1, gallery, dp) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}
