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
    ull m, n; cin >> m >> n;
    vector<ull> x(n);
    F0R(i, n) cin >> x[i];
    ull l = 0, h = 2e9+5, good = 0, need = 0, wtf = 0;
    while(l < h) {
        ull mid = l+(h-l)/2;
        ull tmp = 0, tg = 0, tt = 0;
        F0R(i, n) {
            if(mid < x[i]) {
                tmp += x[i]-mid;
            } else {
                tg += (x[i]*x[i]);
                tt++;
            }
        }
        if(tmp > m) {
            l = mid+1;
        } else {
            h = mid;
            good = tg;
            need = tmp;
            wtf = tt;
        }
    }

    ull ans = 0;

    ans += good;
    ans += (l*l)*(n-wtf-(m-need));
    ans += (l-1)*(l-1)*(m-need);
    
    cout << ans << endl;
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