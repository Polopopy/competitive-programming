/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define sz(x) (int)(x).size()

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
    int n, r; cin >> n >> r;
    FT dih(n+r+1);
    vector<int> pos(n+1);
    for(int i = 1; i < n+1; ++i) {
        pos[i] = i+r;
        dih.update(i+r, 1);
    }
    for(int i = 0; i < r; ++i) {
        int x; cin >> x;
        cout << dih.query(pos[x]) << ' ';
        dih.update(pos[x], -1);
        dih.update(r-i-1, 1);
        pos[x] = r-i-1;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while(T--) solve();
}