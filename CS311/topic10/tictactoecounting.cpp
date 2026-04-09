#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// So I don't go insane writing this:
// 00 for nothing, 01 for X, 10 for O

// 00 00 00 00 00 00 00 00 00
// 16 14 12 10  8  6  4  2  0
// TL TM TR ML MM MR BL BM BR

vector<int> wins = {
    (1<<4) | (1<<2) | (1<<0), // 00 00 00 00 00 00 01 01 01
    (1<<10) | (1<<8) | (1<<6), // 00 00 00 01 01 01 00 00 00
    (1<<16) | (1<<14) | (1<<12), // 01 01 01 00 00 00 00 00 00

    (1<<16) | (1<<10) | (1<<4), // 01 00 00 01 00 00 01 00 00
    (1<<14) | (1<<8) | (1<<2), // TM, MM, BM
    (1<<12) | (1<<6) | (1<<0), // TR, MR, BR

    (1<<16) | (1<<8) | (1<<0), // TL, MM, BR
    (1<<8) | (1<<12) | (1<<4) // TR, MM, BL
};

vector<ll> xw(1<<18), ow(1<<18);
vector<bool> visited(1<<18);

void dfs(int curr, bool x) {
    if(visited[curr]) return;
    visited[curr] = true;

    for(auto mask : wins) {
        if((curr & mask) == mask) {
            xw[curr]++;
            return;
        }
        if((curr & (mask << 1)) == (mask << 1)) {
            ow[curr]++;
            return;
        }
    }

    for(int i = 0; i < 9; ++i) {
        if(((curr >> (2*i)) & 3) == 0) {
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
    dfs(0, true);

    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        int curr = 0;
        for(int j = 0; j < 9; ++j) {
            if(s[j] == 'X') {
                curr |= (1 << (2*j));
            } else if(s[j] == 'O') {
                curr |= (2 << (2*j));
            }
        }

        if(!visited[curr]) {
            cout << "-1 -1" << endl;
        } else {
            cout << xw[curr] << ' ' << ow[curr] << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}