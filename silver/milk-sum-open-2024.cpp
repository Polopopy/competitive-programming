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
const int inf = 1e9+2;
const int mod = 2e9;

void solve() {
	int n; cin >> n;
	vector<ll> pos(n), cows(n), going(n), pref(n+1);
	ll ans = 0;
	F0R(i, n) {
		cin >> cows[i];
		pos[i] = i;
	}
	
	sort(all(pos), [&cows](int a, int b) {return cows[a] < cows[b];});

	F0R(i, n) {
		going[pos[i]] = i;
		ans += cows[pos[i]] * (i+1);
		pref[i+1] = pref[i] + cows[pos[i]];
	}

	int q; cin >> q;
	F0R(i, q) {
		ll target, nval, end_pos, start_pos; cin >> target >> nval;
		target--;
		start_pos = going[target];
		auto it = lower_bound(all(pos), nval, [&cows](int a, int b) {return cows[a] < b;});

		if(it == pos.end()) {
			end_pos = n;
		} else {
			end_pos = going[*it];
		}

		ll output = ans - cows[target] * (start_pos+1);
		if(start_pos >= end_pos) {
			output += nval * (end_pos+1);
			output += pref[start_pos]-pref[end_pos];
		} else if(start_pos < end_pos) {
			output += nval * (end_pos);
			output -= pref[end_pos]-pref[start_pos+1];
		}
		cout << output << endl;
	}
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	// freopen("haybales.in", "r", stdin);
	// freopen("haybales.out", "w", stdout);
 
	// int T;
	// cin >> T;
	// while(T--) {
	//    solve();
	// }
 
	solve();
}