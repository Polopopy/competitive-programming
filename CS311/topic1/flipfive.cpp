/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// all possible moves
vector<vector<pair<int, int>>> moves = 
{
{{0,0}, {0,1}, {1,0}},
{{0,0}, {0,1}, {1,1}, {0,2}},
{{0,1}, {0,2}, {1,2}},
{{0,0}, {1,0}, {1,1}, {2,0}},
{{1,0}, {1,1}, {0,1}, {1,2}, {2,1}},
{{1,1}, {0,2}, {1,2}, {2,2}},
{{1,0}, {2,0}, {2,1}},
{{2,0}, {2,1}, {1,1}, {2,2}},
{{2,1}, {2,2}, {1,2}}
};

void solve() {
    // populate target array
    vector<vector<bool>> target(3, vector<bool>(3));
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            char c; cin >> c;
            target[i][j] = (c=='*');
        }
    }

    int ans = INT_MAX;
    // use a bitmask to try all subsets of moves
    for(int mask = 0; mask < (1 << 9); ++mask) {
        vector<vector<bool>> test(3, vector<bool>(3));
        int tmp = 0;
        for(int i = 0; i < 9; ++i) {
            // if the current bit is 1, apply the move
            if((mask >> i) & 1) {
                for(auto& x : moves[i]) {
                    test[x.first][x.second] = !test[x.first][x.second];
                }
                tmp++;
            }
        }

        // compare to target
        bool bad = false;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(target[i][j] != test[i][j]) {
                    bad = true;
                    break;
                }
            }
            if(bad) break;
        }

        // track best answer
        if(!bad) {
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}