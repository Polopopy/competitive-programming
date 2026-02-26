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
    FT x(n);
    vector<ll> s(n);
    for(int i = 0; i < n; ++i) {
        cin >> s[i];
        x.update(i, 1);
    }
    vector<int> ops(n+1);
    for(int i = 0; i < n; ++i) ops[s[i]] = i;
    ll ans = 0;
    int curr = 0;
    for(int thing = 1; thing <= n; ++thing) {
        int target = ops[thing];
        if(curr > target) {
            ll tmp = x.query(curr) - x.query(target);
            tmp = min(tmp, x.query(n) - x.query(curr) + x.query(target));
            ans += (tmp + 1);
        } else {
            ll tmp = x.query(target) - x.query(curr);
            tmp = min(tmp, x.query(n) - x.query(target) + x.query(curr));
            ans += (tmp + 1);
        }
        x.update(target, -1);
        curr = target;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}