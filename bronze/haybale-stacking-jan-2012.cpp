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
	int n, k; cin >> n >> k;
    vector<ll> pref(n);
    F0R(i, k) {
        int a, b; cin >> a >> b;
        pref[a-1]++;
        pref[b-1]--;
    }

    FOR(i, 1, n) pref[i] += pref[i-1];

    nth_element(pref.begin(), pref.begin() + (n/2+1), pref.end());

    cout << pref[n/2+1] << endl;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	// freopen("stacking.in", "r", stdin);
	// freopen("stacking.out", "w", stdout);
 
	// int T;
	// cin >> T;
	// while(T--) {
	//    solve();
	// }
 
	solve();

	return 0;
}