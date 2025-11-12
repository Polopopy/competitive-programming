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
    ll n; cin >> n;
    vector<double> x(n), y(n), avgs(n);
    F0R(i, n) {
        cin >> x[i];
        x[i] /= (i+1);
    }
    F0R(i, n) cin >> y[i];

    sort(all(y), greater<double>());

    avgs[0] = y[0];
    double ans = avgs[0]+x[0];

    FOR(i, 1, n) {
        avgs[i] = (avgs[i-1]*i+y[i])/(i+1);
        ans = max(ans, avgs[i]+x[i]);
    }
    cout << fixed << setprecision(7) << ans << endl;
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