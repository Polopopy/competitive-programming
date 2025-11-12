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

void solve() {
    int n; cin >> n;
    map<string, int> id;
    map<int, string> rid;
    map<string, vector<string>> tmp;

    set<string> thing;

    string line;
    getline(cin, line);
    int counter = 0;
    F0R(i, n) {
        getline(cin, line);
        istringstream ss(line);
        string c, d;
        while(ss >> c) {
            if(c[sz(c)-1] == ':') {
                c = c.substr(0, sz(c)-1);
                d = c;
                if(thing.find(d) == thing.end()) {
                    id[d] = counter;
                    rid[counter] = d;
                    thing.insert(d);
                    counter++;
                }
            } else {
                tmp[d].pb(c);
                if(thing.find(c) == thing.end()) {
                    id[c] = counter;
                    rid[counter] = c;
                    thing.insert(c);
                    counter++;
                }
            }
        }
    }

    string td; cin >> td;

    vector<vector<int>> adj(n);
    trav(x, tmp) {
        trav(y, x.s) {
            adj[id[x.f]].pb(id[y]);
        }
    }

    vector<int> ot = topo(n, adj);
    vector<string> ans;
    set<int> been;

    R0F(i, n-1) {
        if(sz(been) > 0) {
            trav(x, adj[ot[i]]) {
                if(been.find(x) != been.end() && been.find(ot[i]) == been.end()) {
                    been.insert(ot[i]);
                    ans.pb(rid[ot[i]]);
                }
            }
        } else if(rid[ot[i]] == td) {
            been.insert(id[td]);
            ans.pb(td);
        }
    }

    trav(x, ans) cout << x << endl;
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