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

vector<vector<ll>> pref(maxn, vector<ll>(maxn));

void solve() {
    int n, k; cin >> n >> k;
    int lb = inf, rb = -1, ub = inf, db = -1;
    F0R(i, n) {
        int c1, r1, c2, r2;
        cin >> c1 >> r1 >> c2 >> r2;
        c1++;
        r1++;
        c2++;
        r2++;
        pref[r1][c1]++;
        pref[r2][c2]++;
        pref[r1][c2]--;
        pref[r2][c1]--;
        lb = min(lb, min(c1, c2));
        rb = max(rb, max(c1, c2));
        ub = min(ub, min(r1, r2));
        db = max(db, max(r1, r2));
    }
    int ans = 0;
    FOR(r, ub, db+1) {
        FOR(c, lb, rb+1) {
            pref[r][c] += pref[r][c-1];
        }
    }
    FOR(r, ub, db+1) {
        FOR(c, lb, rb+1) {
            pref[r][c] += pref[r-1][c];
        }
    }

    FOR(r, ub, db+1) {
        FOR(c, lb, rb+1) {
            if(pref[r][c] == k) ans++;
        }
    }

    cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);

	// int T;
	// cin >> T;
	// while(T--) {
	//    solve();
	// }

	solve();

	return 0;
}