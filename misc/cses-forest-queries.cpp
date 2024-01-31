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

const int maxn = 1e3+5;
const int inf = 1e9+2;
const int mod = 2e9;

vector<vector<int>> pref(maxn, vector<int>(maxn));

void solve() {
	int n, q; cin >> n >> q;
    FOR(r, 1, n+1) {
        FOR(c, 1, n+1) {
            char x; cin >> x;
            if(x == '*') {
                pref[r][c]++;
            }
            pref[r][c] += pref[r][c-1];
            pref[r][c-1] += pref[r-1][c-1];
        }
        pref[r][n] += pref[r-1][n];
    }

    F0R(i, q) {
        int r1, r2, c1, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << pref[r2][c2] - pref[r1-1][c2] - pref[r2][c1-1] + pref[r1-1][c1-1] << endl;
    }
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