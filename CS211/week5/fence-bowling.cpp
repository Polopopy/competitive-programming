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
    int k; cin >> k;
    double w, l; cin >> w >> l;

    double lo = 0.0, hi = 3.1415926535/2;
    F0R(rep, 30) {
        double mid = lo+(hi-lo)/2;
        double b = mid;
        double dx = 0.0, dy = 0.0;
        int count = 0;

        while(count < k) {
            if(count == 0) {
                dx += (w/2);
                dy += (w/2) * tan(b);
                b = atan(2*tan(b));
            } else {
                dx += w;
                dy += w * tan(b);
                b = atan(2*tan(b));
            }
            count++;
            if(dy > l) break;
        }

        if(dy <= l) {
            dx += (w/2);
            dy += (w/2) * tan(b);
            b = atan(2*tan(b));
        }

        if(count < k-1) {
            hi = mid;
        } else {
            if(dy > l) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
    }
    cout << lo*180/3.1415926535 << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cout.setf(std::ios::fixed);
    cout << std::setprecision(7);

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