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
const int mod = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> x(n);
    int ev = 0;
    trav(a, x) cin >> a;
    int ans = 0;
    unordered_map<int, int> seen;
    F0R(i, n) {
        trav(a, seen) {
            if(a.f != 1 && x[i] != 1 && (a.f%x[i] == 0 || x[i]%a.f == 0)) {
                ans += a.s;
            }
        }
        ans += ev;
        if(x[i] % 2 == 0) ev++;
        seen[x[i]]++;
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