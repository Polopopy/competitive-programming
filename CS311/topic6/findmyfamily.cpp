/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
typedef long long ll;

// using RMQ because segtrees have more overhead
template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

void solve() {
    int T; cin >> T;
    set<int> ans;
    // for each photo, we can repeat the same process
    for(int tmp = 1; tmp <= T; ++tmp) {
        int n; cin >> n;
        set<int> seen;
        seen.clear();
        vector<int> ppl(n);
        // read all the heights and create RMQ
        for(int i = 0; i < n; ++i) cin >> ppl[i];
        RMQ help(ppl);
        
        seen.insert(ppl[0]);
        // for each possible position of the middle person
        for(int i = 1; i < n-1; ++i) {
            // find the left person (taller than middle but shorter than right)
            auto l = seen.upper_bound(ppl[i]);
            seen.insert(ppl[i]);
            // if there is nobody taller than us to the left, continue
            if(l == seen.end()) continue;
            // find the tallest person to our right
            int r = help.query(i+1, n);
            // if the tallest person to the right is taller than left, the photo
            //   needs more analysis
            if(r > *l) {
                ans.insert(tmp);
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for(auto& x : ans) cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}