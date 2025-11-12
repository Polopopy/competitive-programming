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

const int maxn = 100+5;
const int inf = 1e9+2;
const int mod = 2e9;

vector<vector<ll>> adj(maxn);

void gen(vector<pair<ll, ll>>& curr) {
    map<ll, ll> td;
    trav(x, curr) {
        trav(y, adj[x.f]) td[y] += x.s;
    }
    curr.clear();
    trav(x, td) curr.pb(x);
}

void solve() {
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    F0R(i, m) {
        ll a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<pair<ll, ll>> curr = {{s, 1}};

    F0R(i, t) gen(curr);

    ll ans = 0;
    trav(x, curr) ans += x.s;
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