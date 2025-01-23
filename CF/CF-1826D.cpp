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

vector<int> arr(maxn), pref(maxn), suff(maxn);

void solve() {
	int n, ans = 0; cin >> n;

    F0R(i, n) {
        cin >> arr[i];
        pref[i] = arr[i] + i;
        suff[i] = arr[i] - i;
    }

    FOR(i, 1, n) {
        pref[i] = max(pref[i-1], pref[i]);
    }

    ROF(i, n-2, 0) {
        suff[i] = max(suff[i+1], suff[i]);
    }
    
    FOR(i, 1, n-1) {
        ans = max(ans, pref[i-1] + arr[i] + suff[i+1]);
    }

    cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("fname.in", "r", stdin);
	// freopen("fname.out", "w", stdout);

	int T;
	cin >> T;
	while(T--) {
	   solve();
	}

	// solve();

	return 0;
}