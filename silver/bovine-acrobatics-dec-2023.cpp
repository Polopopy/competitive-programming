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

const int maxd = 1e5+5;
const int inf = 1e9+2;
const int mod = 2e9;

struct cow {
    int weight, cnt;
};

bool comp(cow a, cow b) {
    return a.weight > b.weight;
}

void solve() {
	int n, m, k; cin >> n >> m >> k;

    vector<cow> cows(n);
    F0R(i, n) {
        cin >> cows[i].weight >> cows[i].cnt;
    }

    sort(all(cows), comp);\

    deque<cow> dq;
    ll ans = 0;
    int curr = 0;

    while(curr < n && ans < m) {
        if(ans + cows[curr].cnt <= m) {
            dq.pb(cows[curr]);
            ans += cows[curr].cnt;
            cows[curr].cnt = 0;
            curr++;
        } else {
            int diff = m-ans;
            dq.pb({cows[curr].weight, diff});
            cows[curr].cnt -= diff;
            ans += diff;
        }
    }
    
    while(curr < n) {
        cow c = dq.front();
        int tmpweight = cows[curr].weight;
        int tmpcnt = cows[curr].cnt;
        if(c.weight - cows[curr].weight >= k) {
            int diff = min(c.cnt, cows[curr].cnt);
            cows[curr].cnt -= diff;
            dq.front().cnt -= diff;

            if(dq.back().weight == cows[curr].weight) {
                dq.back().cnt += diff;
            } else {
                dq.pb({cows[curr].weight, diff});
            }

            if(cows[curr].cnt == 0) {
                curr++;
            }
            if(c.cnt == 0) {
                dq.pop_front();
            }
            ans += diff;
        } else {
            curr++;
        }
    }

    cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("case.in", "r", stdin);

	// freopen("moocast.in", "r", stdin);
	// freopen("moocast.out", "w", stdout);

	// int T;
	// cin >> T;
	// while(T--) {
	//    solve();
	// }

	solve();
}