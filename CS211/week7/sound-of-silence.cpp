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

const int maxn = 1e6+5;
const int inf = 1e9+2;
const int mod = 2e9;

vector<int> x(maxn);

void solve() {
    int n, m, c; cin >> n >> m >> c;
    F0R(i, n) cin >> x[i];

    vector<int> ans;
    multiset<int> ms;

    F0R(i, m) ms.insert(x[i]);
    if(*ms.rbegin()-*ms.begin() <= c) ans.pb(1);

    FOR(i, m, n) {
        ms.insert(x[i]);
        ms.erase(ms.find(x[i - m]));
        if(*ms.rbegin()-*ms.begin() <= c) ans.pb(i-m+2);
    }

    if(ans.empty()) {
        cout << "NONE" << endl;
    } else {
        trav(x, ans) cout << x << endl;
    }
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