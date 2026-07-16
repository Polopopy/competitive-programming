/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
impl for this problem is trivial so I'll put the math here for code bonus

easy observation: n can't be odd otherwise we can't fill it with 2x1 dominoes (odd % even != 0)

for 0 width, we do nothing -> 1 way
for 2 width, we can fill it with 1 horizontal + 2 vertical, 2 vertical + 1 horizontal, OR 3 horizontal -> 3 ways
for 4 width, we can fill it similarly but we also consider another case:
    - if we use two horizontal on top (or bottom), we have a 2x4, then we can fill that in with 1 vertical + 2 horizontal + 1 vertical
    this kind of uses the 2 horizontal to connect two otherwise invalid structures
    - so we see 4 is built on two things:
        - 3 * 2 case -> 3 ways to fill the new space simply
        - 2 * 0 case -> 2 ways to use the connector thing


so we see that dp[i] = 3*dp[i-2] + 2*dp[i-4] + ... + 2*dp[0]

but we also have dp[i-2] = 3*dp[i-4] + 2*dp[i-6] + ... 2*dp[0];

so dp[i] is just 3*dp[i-2] + dp[i-2] - dp[i-4] = 4*dp[i-2] - dp[i-4]

sorry, explaining it is a lot harder when I can't draw things out

*/

void solve() {
    // precompute all possible states
    vector<int> dp(31);
    dp[0] = 1;
    dp[2] = 3;
    for(int i = 4; i < 31; i+=2) dp[i] = 4 * dp[i-2] - dp[i-4];

    // print out precomputed answer
    int n;
    while(cin >> n && n != -1) cout << dp[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}