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
    int n; cin >> n;
    map<string, int> m;
    F0R(i, n) {
        string a, b; cin >> a >> b;
        m[(a.substr(0, 2) + b)]++;
    }

    ll ans = 0;
    trav(x, m) {
        string tmp = (x.f.substr(2) + x.f.substr(0, 2));
        if(x.f != tmp) ans += x.s * m[tmp];
    }

    cout << ans/2 << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);

    // int T;
    // cin >> T;
    // while(T--) {
    //    solve();
    // }

    solve();

    return 0;
}