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
	int n, m, r; cin >> n >> m >> r;
	vector<ll> cows(n);
	F0R(i, n) cin >> cows[i];
	sort(all(cows), greater<ll>());

	vector<pair<ll, ll>> stores(m);
	F0R(i, m) {
		int a, b; cin >> a >> b;
		stores[i] = {b, a};
	}

	sort(all(stores), greater<pair<ll, ll>>());

	vector<ll> rent(r);
	F0R(i, r) cin >> rent[i];

	sort(all(rent), greater<ll>());

	vector<ll> profits(n);

	int store = 0, cow = 0;
	while(cow < n && store < m) {
		if(stores[store].s >= cows[cow]) {
			profits[cow] += stores[store].f * cows[cow];
			stores[store].s -= cows[cow];
			cow++;
		} else {
			profits[cow] += stores[store].f * stores[store].s;
			cows[cow] -= stores[store].s;
			store++;
		}
	}

	ll ans = 0;

	F0R(i, n) {
		profits[n-i-1] = max(profits[n-i-1], rent[i]);
		ans += profits[n-i-1];
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("rental.in", "r", stdin);
	freopen("rental.out", "w", stdout);

	// int T;
	// cin >> T;
	// while(T--) {
	//    solve();
	// }

	solve();

	return 0;
}