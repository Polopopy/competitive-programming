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

/* -----------------------------------------------------------
   Kahn's Algorithm (in-degree method) for Topological Sort
   Returns:
     - vector<int> of size n with a topological order if DAG
     - empty vector if a cycle exists (no topo order)
   Complexity: O(n + m)
----------------------------------------------------------- */
vector<int> topo(int n, const vector<vector<int>>& g) {
    vector<int> in(n,0);
    F0R(u,n) trav(v,g[u]) ++in[v];
    deque<int> q; F0R(i,n) if(!in[i]) q.pb(i);
    vector<int> o; o.reserve(n);
    while(!q.empty()){
        int u=q.front(); q.pop_front();
        o.pb(u);
        trav(v,g[u]) if(--in[v]==0) q.pb(v);
    }
    if(sz(o)!=n) return {};
    return o;
}


/* -----------------------------------------------------------
   Helper: build adjacency from edge list (0-indexed)
----------------------------------------------------------- */
vector<vector<int>> build_adj(int n, const vector<pair<int,int>>& edges) {
    vector<vector<int>> adj(n);
    trav(e, edges) adj[e.f].pb(e.s);
    return adj;
}

void solve() {
    // Optional I/O:
    // Reads: n m, followed by m directed edges u v (0-indexed).
    // If no input is provided, exit quietly.
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<pair<int,int>> edges; edges.reserve(m);
    F0R(i, m) {
        int u, v; cin >> u >> v;
        edges.pb({u, v});
    }

    auto adj = build_adj(n, edges);
    auto order = topo(n, adj);

    if (order.empty()) {
        cout << "cycle detected\n";
    } else {
        trav(u, order) cout << u << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    // freopen("filename.in", "r", stdin);
    // freopen("filename.out", "w", stdout);

    // int T;
    // cin >> T;
    // while(T--) solve();

    solve();
}
