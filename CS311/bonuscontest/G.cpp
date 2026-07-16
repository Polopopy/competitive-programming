#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)
#define R0F(i, a) ROF(i, a, 0)
#define trav(a,x) for (auto& a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define ins insert
#define endl '\n'

const int maxn = 1e5+5;
const int inf = 2e9+2;
const int mod = 1e7+6;

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
    string s; cin >> s;
    int n = sz(s);
    int m; cin >> m;
    queue<int> td;
    FT ft(n);
    bool counting = false;
    ROF(i, n-1, 0) {
        if(s[i] != 'A') counting = true;
        if(counting) {
            ft.update(i, 1);
            if(s[i] == 'A') {
                td.push(i);
            }
        }
    }
    int diff = 0;

    while(!td.empty()) {
        int curr = td.front();
        td.pop();
        int x = ft.query(n) - ft.query(curr+1);
        if(m > x) {
            m -= x;
            diff += x;
        } else {
            diff += m;
            m = 0;
            break;
        }
    }

    ll ans = 0;
    int as = 0;
    F0R(i, n) {
        if(s[i] == 'A') as++;
        else ans += as;
    }
    cout << ans - diff << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    // freopen("filename.in", "r", stdin);
    // freopen("filename.out", "w", stdout);

    // int T;
    // cin >> T;
    // while(T--) {
    //     solve();
    // }

    solve();
}