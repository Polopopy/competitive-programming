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
const int inf = 2e9+2;
const int mod = 1e7+6;

void solve() {
    int n; cin >> n;

    unordered_map<int, vector<int>> t2p, p2t;
    
    FOR(i, 1, n+1) {
        int m; cin >> m;
        F0R(j, m) {
            int x; cin >> x;
            t2p[x].pb(i);
            p2t[i].pb(x);
        }
    }

    vector<bool> visited(n+1);
    deque<int> td;
    td.pb(1);
    visited[1] = true;
    vector<pair<pair<int, int>, int>> ans;

    while(!td.empty()) {
        int c = td.front();
        td.pop_front();

        if(sz(ans) == n-1) break;

        trav(x, p2t[c]) {
            trav(nx, t2p[x]) {
                if(!visited[nx]) {
                    visited[nx] = true;
                    td.pb(nx);
                    ans.pb({{c, nx}, x});
                }
            }
        }
    }

    if(sz(ans) != n-1) {
        cout << "impossible" << endl;
    } else {
        trav(x, ans) {
            cout << x.f.f << ' ' << x.f.s << ' ' << x.s << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    // freopen("filename.in", "r", stdin);
    // freopen("filename.out", "w", stdout);

    // int T;
    // cin >> T;
    // while(T--) {
    //     solve();
    // }

    solve();
}