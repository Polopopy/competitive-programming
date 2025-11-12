/*

Author: Ray Han
It is ok to share my code anonymously for educational purposes

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// maxn is the largest possible n + 5
static const int maxn = 5e4 + 5;

vector<int> nums(maxn);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) cin >> nums[i];

    long long total_decrements = 0;
    
    // loop backwards (right to left), killing as few people as possible
    //  to satisfy requirements
    for(int i = n-2; i >= 0; i--) {

        int needed = nums[i] - nums[i + 1] + 1;
        if(needed > 0) {
            nums[i] -= needed;

            // if negative, immediately print 1 and terminate
            if(nums[i] < 0) {
                cout << 1 << '\n';
                return 0;
            }

            total_decrements += needed;
        }
    }

    cout << total_decrements << '\n';

    return 0;
}
