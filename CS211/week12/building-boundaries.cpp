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
    vector<ll> x(3), y(3);
    cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];

    ll ans = 1LL << 62;
    // all horizontal
    ans = min(ans, (x[0]+x[1]+x[2])*max(y[0], max(y[1], y[2])));
    //all vert
    ans = min(ans, (y[0]+y[1]+y[2])*max(x[0], max(x[1], x[2])));

    F0R(bl, 3) {
        F0R(br, 3) {
            F0R(t, 3) {
                if(bl != br && bl != t && t != br) {
                    ll w1 = max(x[bl]+x[br], x[t]);
                    ll h1 = max(y[bl]+y[t], y[br]);
                    ll w2 = max(x[bl]+x[br], x[bl]+x[t]);
                    ll h2 = max(y[bl], y[br]+y[t]);

                    ans = min(ans, w1*h1);
                    ans = min(ans, w2*h2);

                    if (ans == 9) {
                        cout << "HI" << endl;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    // freopen("filename.in", "r", stdin);
    // freopen("filename.out", "w", stdout);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }

    // solve();
}