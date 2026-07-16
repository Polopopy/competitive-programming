/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// 00 for nothing, 01 for X, 10 for O

// Helpful map for manually entering board states
// 00 00 00 00 00 00 00 00 00
// 16 14 12 10  8  6  4  2  0
// TL TM TR ML MM MR BL BM BR

// hardcode board states that result in a victory
vector<int> wins = {
    // full row
    (1<<4) | (1<<2) | (1<<0), // 00 00 00 00 00 00 01 01 01
    (1<<10) | (1<<8) | (1<<6), // 00 00 00 01 01 01 00 00 00
    (1<<16) | (1<<14) | (1<<12), // 01 01 01 00 00 00 00 00 00

    // full column
    (1<<16) | (1<<10) | (1<<4), // 01 00 00 01 00 00 01 00 00
    (1<<14) | (1<<8) | (1<<2), // TM, MM, BM
    (1<<12) | (1<<6) | (1<<0), // TR, MR, BR

    // full diagonal
    (1<<16) | (1<<8) | (1<<0), // TL, MM, BR
    (1<<8) | (1<<12) | (1<<4) // TR, MM, BL
};

// track number of wins for X and O
vector<ll> xw(1<<18), ow(1<<18);
vector<bool> visited(1<<18);

// DFS to precompute all possible board states
void dfs(int curr, bool x) {
    if(visited[curr]) return;
    visited[curr] = true;

    // for each "winning" bitmask, compare it to the board state
    for(auto mask : wins) {
        // if our game is over, increment the winner and return
        if((curr & mask) == mask) {
            xw[curr]++;
            return;
        }
        if((curr & (mask << 1)) == (mask << 1)) {
            ow[curr]++;
            return;
        }
    }
    // for each possible next move, check if it is legal to make
    for(int i = 0; i < 9; ++i) {
        // bitwise operator for checking if it is legal
        if(((curr >> (2*i)) & 3) == 0) {
            // create next board state bit representation and continue dfs
            int tmp = x? 1:2;
            int nx = curr | (tmp << (2*i));
            dfs(nx, !x);

            xw[curr] += xw[nx];
            ow[curr] += ow[nx];
        }
    }
}

void solve() {
    int n; cin >> n;
    // precompute all board states
    dfs(0, true);

    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        int curr = 0;
        for(int j = 0; j < 9; ++j) {
            // create our input bit representation
            if(s[j] == 'X') {
                curr |= (1 << (2*j));
            } else if(s[j] == 'O') {
                curr |= (2 << (2*j));
            }
        }

        // if the board state is impossible, output -1 -1
        if(!visited[curr]) {
            cout << "-1 -1" << endl;
        } else {
            // otherwise, just print the precomputed win counts from our current state
            cout << xw[curr] << ' ' << ow[curr] << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}