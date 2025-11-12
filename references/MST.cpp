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

struct DSU {
    vector<int> p, sz;
    DSU(int n=0){ init(n); }
    void init(int n){ p.resize(n); sz.assign(n,1); F0R(i,n) p[i]=i; }
    int find(int x){
        while(p[x]!=x){ p[x]=p[p[x]]; x=p[x]; }
        return x;
    }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a; sz[a]+=sz[b];
        return true;
    }
};

struct Edge {
    int u, v, w;
};

ll mst_kruskal(int n, vector<Edge> edges) {
    sort(all(edges), [](const Edge& A, const Edge& B){ return A.w < B.w; });
    DSU dsu(n);
    ll sum = 0;
    int used = 0;
    trav(e, edges){
        if (dsu.unite(e.u, e.v)) {
            sum += e.w;
            if (++used == n-1) break;
        }
    }
    return (used == n-1) ? sum : -1;
}

ll mst_prim(int n, const vector<vector<pair<int,int>>>& g) {
    vector<char> vis(n, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.emplace(0, 0);
    ll sum = 0; int cnt = 0;

    while (!pq.empty() && cnt < n) {
        auto [w, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1; sum += w; ++cnt;
        for (auto &e : g[u]) if (!vis[e.f]) pq.emplace(e.s, e.f);
    }
    return (cnt == n) ? sum : -1;
}


void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<Edge> edges; edges.reserve(m);
    vector<vector<pair<int,int>>> g(n);

    F0R(i, m){
        int u, v, w; cin >> u >> v >> w;
        --u; --v;
        edges.pb({u, v, w});
        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    cout << mst_kruskal(n, edges) << endl;
    cout << mst_prim(n, g) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    // freopen("filename.in", "r", stdin);
    // freopen("filename.out", "w", stdout);

    solve();
}
