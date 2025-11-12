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

const int maxn = 1e4+5;
const int inf = 1e9+2;
const int mod = 2e9;

int n, k;
vector<int> x(maxn);
map<int, int> m;

void solve() {
    while(cin >> n && n != 0) {
        k = -1;
        m.clear();
        F0R(i, n) {
            cin >> x[i];
            m[x[i]]++;
            k = max(k, m[x[i]]);
        }

        int r = 0;
        vector<vector<int>> output(k+1);
        for(auto it = m.begin(); it != m.end();) {
            output[r].pb(it->first);
            it->second--;
            r++;
            r %= k;
            if(it->second == 0) it++;
        }
        cout << k << endl;
        trav(v, output) {
            trav(a, v) cout << a << ' ';
            cout << endl;
        }
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