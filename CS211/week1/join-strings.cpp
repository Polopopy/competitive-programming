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

void output(int start, vector<pair<vector<int>, bool>>& adj, vector<string>& s) {
	cout << s[start];
	trav(x, adj[start].f) {
		output(x, adj, s);
	}
}

void solve() {
	int n; cin >> n;
	vector<string> s(maxn);
	vector<pair<vector<int>, bool>> adj(maxn);
	F0R(i, n) cin >> s[i];
	int start = -1;

	F0R(i, n-1) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].f.pb(b);
		adj[b].s = true;
		if(i == n-2) start = a;
	}

	F0R(i, n) {
		if(!adj[i].s) {
			output(i, adj, s);
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);

	// freopen("fname.in", "r", stdin);
	// freopen("fname.out", "w", stdout);

	// int T;
	// cin >> T;
	// while(T--) {
	//    solve();
	// }

	solve();

	return 0;
}