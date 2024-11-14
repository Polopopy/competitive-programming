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
#define YN(x) cout << (x ? "YES" : "NO") << endl

const int maxn = 1e5+5;
const int inf = 1e9+2;
const int mod = 2e9;

int nCr(int n, int r) {
    if(r > n || r == 0 || n == 0) return 0;
    double ret = 0;
    F0R(i, r) ret += log(n-i) - log(i+1);
    return (int)round(exp(ret));
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    bool ans = true;

    if(ans && m < n-1) ans = false; // not enough
    if(ans && m > n-1) { // too many and can't remove enough
        int to_remove = m - n + 1;
        int can_remove = nCr(n/k, k);
        if(to_remove > can_remove) ans = false;
    }

    YN(ans);
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