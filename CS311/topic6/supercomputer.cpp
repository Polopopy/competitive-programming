/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// summation segtree
struct Tree {
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a + b; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

void solve() {
    int n, q; cin >> n >> q;
    Tree seg(n);
	// segtree for the bits themselves
    for(int i = 0; i < q; ++i) {
        char op; cin >> op;
		// simulate each query
        if(op == 'F') {
            int x; cin >> x;
			// find the bit we want and flip it
            int tmp = seg.query(x-1, x);
            seg.update(x-1, tmp^1);
        } else {
            int l, r; cin >> l >> r;
			// query all 1 bits by summing in a range (0s have no impact)
            cout << seg.query(l-1, r) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}