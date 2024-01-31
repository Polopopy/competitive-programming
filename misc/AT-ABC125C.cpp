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

int n, ans;
vector<int> pref(maxn), suf(maxn), arr(maxn);

void solve() {
    cin >> n;
	FOR(i, 1, n+1) {
		cin >> arr[i];
		pref[i] = __gcd(pref[i-1], arr[i]);
	}

	ROF(i, n, 1) suf[i] = __gcd(suf[i+1], arr[i]);
	FOR(i, 1, n+1) ans = max(ans, __gcd(pref[i-1], suf[i+1]));

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

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