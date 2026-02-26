/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define endl '\n'
typedef long long ll;

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

void solve() {
    int n;
    while(cin >> n && n != 0) {
        vector<ll> yrs(n), rain(n);
        for(int i = 0; i < n; ++i) cin >> yrs[i] >> rain[i];
        RMQ dih(rain);
        int q; cin >> q;
        for(int i = 0; i < q; ++i) {
            int x, y; cin >> x >> y;
            int a = upper_bound(yrs.begin(), yrs.end(), x) - yrs.begin();
            int b = lower_bound(yrs.begin(), yrs.end(), y) - yrs.begin();
            
            bool l = (a > 0 && yrs[a-1] == x);
            bool r = (b < n && yrs[b] == y);

            ll big = 0;
            if(a < b) big = dih.query(a, b);

            if(l && r && rain[a-1] <= rain[b]) {
                // x > y
                cout << "false" << endl;
            } else if(l && big >= rain[a-1]) {
                // z > x
                cout << "false" << endl;
            } else if(r && big >= rain[b]) {
                // z > y and x has no data
                cout << "false" << endl;
            } else if(!r || !l || (b-a+1 != y-x)) {
                // not enough data
                cout << "maybe" << endl;
            } else {
                cout << "true" << endl;
            }
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}