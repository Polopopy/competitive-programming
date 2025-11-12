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
    int n;
    double k;
    cin >> n >> k;
    vector<double> a(n);
    F0R(i, n) cin >> a[i];

    if(n == 1) {
        cout << a[0] << endl;
        return;
    } else if(n == 2) {
        cout << max(a[0], a[1]) << endl;
        return;
    }

    double ans = -1;
    F0R(rep, 1000000) {
        a[0] = max(a[0], a[1]/2 + k);
        ans = max(ans, a[0]);
        a[n-1] = max(a[n-1], a[n-2]/2 + k);
        ans = max(ans, a[n-1]);
        FOR(i, 1, n-1) {
            a[i] = max(a[i], (a[i-1]+a[i+1])/2 + k);
            ans = max(ans, a[i]);
        }
    }
    cout << fixed << setprecision(7) << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    solve();

    return 0;
}