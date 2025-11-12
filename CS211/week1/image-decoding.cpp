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
	int n;
	bool first = true;
	while(cin >> n && n != 0) {
		if(!first) cout << endl;
		first = false;
		int lsize = -1;
		bool bad = false;
		F0R(i, n) {
			int csize = 0;
			char c; cin >> c;
			bool dot = (c=='.');
			int x;
			while(cin >> x) {
				csize += x;
				cout << string(x, (dot? '.':'#'));
				dot = !dot;
				if(cin.peek() == '\n') break;
			}
			if(lsize == -1) lsize = csize;
			if(lsize != csize) bad = true;
			cout << endl;
		}
		if(bad) cout << "Error decoding image" << endl;
	}
	return;
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