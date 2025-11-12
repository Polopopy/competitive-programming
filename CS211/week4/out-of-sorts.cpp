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

bool bs(vector<ll>& seq, ll x) {
    ll l = 0, h = sz(seq)-1;
    while(l <= h) {
        ll m = l+(h-l)/2;
        if(seq[m] == x) return true;
        if(seq[m] < x) {
            l = m+1;
        } else {
            h = m-1;
        }
    }
    return false;
}

void solve() {
    ll n, m, a, c, start, ans=0;
    cin >> n >> m >> a >> c >> start;
    vector<ll> seq(n);
    seq[0] = (a*start+c)%m;
    FOR(i, 1, n) seq[i] = (a*seq[i-1]+c)%m;

    trav(x, seq) if(bs(seq, x)) ans++;

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