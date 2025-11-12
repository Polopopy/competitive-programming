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
    int n, h; cin >> n >> h;
    vector<int> pl(h+1), ph(h+1);
    F0R(i, n) {
        int x; cin >> x;
        if(i % 2 == 0) {
            pl[1]++;
            pl[x+1]--;
        } else {
            ph[h-x+1]++;
            ph[h+1]--;
        }
    }

    int ans = inf, count = 0;

    FOR(i, 1, h+1) {
        pl[i] += pl[i-1];
        ph[i] += ph[i-1];
        int tmp = pl[i]+ph[i];
        if(ans > tmp) {
            ans = tmp;
            count = 1;
        } else if(ans == tmp) {
            count++;
        }
    }

    cout << ans << ' ' << count << endl;
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