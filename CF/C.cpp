#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)
#define R0F(i, a) ROF(i, a, 0)
#define trav(a, x) for (auto &a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define ins insert
#define endl '\n'

const int maxn = 1e5 + 5;
const int inf = 2e9 + 5;
const int mod = 2e9;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    F0R(i, n) cin >> a[i];
    F0R(i, n) cin >> b[i];

    int ans = 0;
    if(n > 1) {
        int tmp = gcd(a[1], a[0]);
        if(a[0] != tmp && b[0] > tmp) {
            a[0] = tmp;
            ans++;
        }
    }
    FOR(i, 1, n-1) {
        int dih = lcm(gcd(a[i], a[i-1]), gcd(a[i], a[i+1]));
        if(a[i] != dih && b[i] > dih) {
            a[i] = dih;
            ans++;
        }
    }
    if(n > 1) {
        int tmp = gcd(a[n-1], a[n-2]);
        if(a[n-1] != tmp && b[n-1] > tmp) {
            ans++;
            a[n-1] = tmp;
        }
    }

    // trav(x, a) cout << x << ' ';
    // cout << endl;

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    // freopen("filename.in", "r", stdin);
    // freopen("filename.out", "w", stdout);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    // solve();
}