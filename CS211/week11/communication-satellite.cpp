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
const int mod = 1e7+6;

double mst_prim(int n, const vector<vector<pair<int,double>>>& g) {
    vector<bool> vis(n, 0);
    priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
    pq.push({0.0, 0});
    double sum = 0;
    int cnt = 0;
     while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1; sum += w; ++cnt;
        for (auto &e : g[u]) if (!vis[e.first]) pq.push({e.second, e.first});
    }
    return (cnt == n) ? sum : -1;
}

void solve() {
    int n; cin >> n;
    vector<int> rs(n);
    vector<pair<double,double>> pos(n);
    vector<vector<pair<int,double>>> g(n);

    F0R(i, n) {
        int a, b, r;
        cin >> a >> b >> r;
        pos[i] = {a,b};
        rs[i] = r;
    }

    F0R(i, n) {
        F0R(j, n) {
            if(i == j) continue;
            double dist = sqrt(pow(pos[i].f-pos[j].f,2)+pow(pos[i].s-pos[j].s,2));
            dist -= rs[i];
            dist -= rs[j];
            g[i].pb({j, dist});
            g[j].pb({i, dist});
        }
    }

    double ans = mst_prim(n, g);
    cout << fixed << setprecision(8) << ans << endl;
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