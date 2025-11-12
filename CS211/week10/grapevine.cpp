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
    int n, m, p;
    cin >> n >> m >> p;

    map<string, int> id;
    vector<pair<string, int>> ppl(n);
    vector<vector<int>> adj(n);

    F0R(i, n) {
        cin >> ppl[i].f >> ppl[i].s;
        id[ppl[i].f] = i;
    }

    F0R(i, m) {
        string a, b; cin >> a >> b;
        adj[id[a]].pb(id[b]);
        adj[id[b]].pb(id[a]);
    }

    string init;
    cin >> init;

    vector<int> count(n), start(n, inf), evil(n, inf);

    deque<int> td;
    td.pb(id[init]);
    evil[id[init]] = 1;
    start[id[init]] = 0;

    int ans = 0;

    while(!td.empty()) {
        auto x = td.back();
        td.pop_back();

        trav(a, adj[x]) {
            count[a]++;
            start[a] = min(start[a], evil[x]);

            if(count[a] == ppl[a].s) {
                evil[a] = evil[x]+1;
                td.pb(a);
            }
        }
    }

    F0R(i, n) {
        if(start[i] <= p) {
            ans++;
        }
    }

    ans--;
    cout << ans << endl;
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