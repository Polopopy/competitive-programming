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

bool comp(pair<int, int>& a, pair<int, int>& b) {
	if(a.f != b.f) {
		return a.f < b.f;
	} else {
		return a.s > b.s;
	}
}

void solve() {
	int n; cin >> n;
    vector<pair<int, int>> mtns(n);
	vector<bool> blocked(n, false);
    F0R(i, n) cin >> mtns[i].f >> mtns[i].s;

	sort(all(mtns), comp);

	int freach = 0, ans = 0;

	F0R(i, n) {
		int creach = mtns[i].f + mtns[i].s;
		if(mtns[i].f < freach && freach-mtns[i].f >= mtns[i].s) {
			blocked[i] = true;
		}
		freach = max(freach, creach);
	}

	R0F(i, n-1) {
		int creach = mtns[i].f - mtns[i].s;
		if(mtns[i].f > freach && mtns[i].f-freach >= mtns[i].s) {
			blocked[i] = true;
		} else {
			if(!blocked[i]) {
				ans++;
			}
		}
		freach = min(freach, creach);
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);

	// int T;
	// cin >> T;
	// while(T--) {
	//    solve();
	// }

	solve();

	return 0;
}