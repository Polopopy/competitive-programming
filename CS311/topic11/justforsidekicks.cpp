#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)(x).size()

typedef long long ll;

// fenwick from kactl
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
    int n, q; cin >> n >> q;
    vector<ll> vals(6);
    for(int i = 0; i < 6; ++i) cin >> vals[i];
    string s; cin >> s;
    vector<FT> dih(6, FT(n));
    vector<int> info(n);
    for(int i = 0; i < (int)s.size(); ++i) {
        info[i] = s[i]-'1';
        dih[info[i]].update(i, 1);
    }

    for(int x = 0; x < q; ++x) {
        int t; cin >> t;
        if(t == 1) {
            int k, p; cin >> k >> p;
            k--;
            p--;
            dih[info[k]].update(k, -1);
            info[k] = p;
            dih[p].update(k, 1);
        } else if(t == 2) {
            int p, v; cin >> p >> v;
            p--;
            vals[p] = v;
        } else if(t == 3) {
            int l, r; cin >> l >> r;
            ll ans = 0;
            for(int i = 0; i < 6; ++i) {
                ll tmp = dih[i].query(r) - dih[i].query(l-1);
                tmp *= vals[i];
                ans += tmp;
            }
            cout << ans << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}