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

const int maxn = 105;
const int inf = 1e9+2;
const int mod = 2e9;

ll t;
ll n, m;
vector<pair<ll, ll>> monk(maxn), eys(maxn);

void solve() {
    cin >> t >> n;
    F0R(i, n) cin >> monk[i].f >> monk[i].s;
    cin >> m;
    F0R(i, m) cin >> eys[i].f >> eys[i].s;
    ll l = 0, h = t+1;
    while(l < h) {
        ll mid = l+(h-l)/2;
        ll p1 = 0, p2 = 0;
        F0R(i, n) {
            if(mid >= monk[i].f) p1 += (mid-monk[i].f)/monk[i].s + 1;
        }
        F0R(i, m) {
            if((t-mid-1) >= eys[i].f) p2 += ((t-mid-1)-eys[i].f)/eys[i].s + 1;
        }
        if(p1 < p2) {
            l = mid+1;
        } else {
            h = mid;
        }
    }
    cout << l << endl;
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