#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*

1 paint stroke covers any range (l,r)
minimum number of strokes to create given array?

10
1 2 3 4 1 4 3 2 1 6

dp[l][r] is the min num of strokes to create [l,r]
dp[l][r] = min(dp[l+1][r]+1, dp[l+1][p-1] + dp[p][r]) where p are other instances of arr[l]

*/

int query(vector<vector<int>>& dp, int l, int r) {
    if(l > r) return 0;
    return dp[l][r];
}

void solve() {
    int n; cin >> n;
    vector<int> x(n);
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    for(int i = 0; i < n; ++i){
        cin >> x[i];
        dp[i][i] = 1;
    }

    for(int w = 1; w < n; ++w) {
        for(int l = 0; l < n-w; ++l) {
            int r = l+w;
            dp[l][r] = dp[l+1][r] + 1;
            for(int p = l+1; p <= r; ++p) {
                if(x[p] == x[l]) {
                    dp[l][r] = min(dp[l][r], query(dp, l+1, p-1) + query(dp, p, r));
                }
            }
        }
    }
    /*for(int i = 0; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }*/
    cout << dp[0][n-1] << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}
