/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)(x).size()
typedef long long ll;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

void solve() {
    int n; cin >> n;
    unordered_map<int, int> pos;
    FT fen(n);
    // initialize fenwick tree to all 1s indicating all numbers are
    //   in their original positions
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        // save actual indices of each value 1...n
        pos[x] = i;
        fen.update(i, 1);
    }

    // key: after a number is put in position, it won't be in the way
    //   of any other numbers moving to their final positions
    int l = 1, r = n;
    for(int i = 0; i < n; ++i) {
        // loop with a condition to determine whether we are searching for
        //   the smallest or biggest number right now
        if(i % 2 == 0) {
            // query for the next small number and count how many numbers
            //   stand in the way of this number and its final position
            cout << fen.query(pos[l]) << endl;
            // set to 0 to indicate it is no longer there
            fen.update(pos[l], -1);
            l++;
        } else {
            // query for the next large number and count how many numbers
            //   stand in the way of this number and its final position
            cout << (fen.query(n) - fen.query(pos[r]+1)) << endl;
            // set to 0 to indicate it is no longer there
            fen.update(pos[r], -1);
            r--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}