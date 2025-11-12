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
    ll a = 0, b = 0;
    vector<pair<double, int>> stones;
    F0R(rep, 10) {
        stones.clear();
        ll n; cin >> n;
        F0R(i, n) {
            double x, y; cin >> x >> y;
            stones.pb({sqrt((x-114)*(x-114)+(y-84)*(y-84)), 1});
        }
        ll m; cin >> m;
        F0R(i, m) {
            double x, y; cin >> x >> y;
            stones.pb({sqrt((x-114)*(x-114)+(y-84)*(y-84)), 2});
        }

        if(m == 0 && n == 0) {
            continue;
        } else if(n == 0) {
            b += m;
        } else if(n == 0) {
            a += n;
        } else {
            sort(all(stones));
            bool yay = (stones[0].s==1);
            if(yay) {
                a++;
            } else {
                b++;
            }

            FOR(i, 1, (m+n)) {
                if(stones[i].s == stones[i-1].s) {
                    if(yay) {
                        a++;
                    } else {
                        b++;
                    }
                } else {
                    break;
                }
            }
        }
    }
    cout << a << ' ' << b << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    // freopen("fname.in", "r", stdin);
    // freopen("fname.out", "w", stdout);

    // int T;
    // cin >> T;
    // while(T--) {
    //    solve();
    // }

    solve();

    return 0;
}