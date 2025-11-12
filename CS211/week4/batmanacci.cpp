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

const int maxn = 1e2+5;
const int inf = 1e9+2;
const int mod = 2e9;

vector<ll> fibs(maxn);

int fib_gen(ll k) {
    fibs[0] = 1;
    fibs[1] = 1;
    int i = 2;
    while(fibs[i-1] <= k) {
        fibs[i] = fibs[i-1]+fibs[i-2];
        i++;
    }
    return i;
}

void solve() {
    ll n, k; cin >> n >> k;
    if(k == 1) {
        cout << (n%2 == 0? 'A':'N') << endl;
    } else if(k == 2) {
        cout << (n%2 == 1? 'A':'N') << endl;
    } else {
        k--;
        int i = fib_gen(k);
        while(i > 1) {
            if(k < fibs[i-2]) {
                i -= 2;
            } else {
                k -= fibs[i-2];
                i--;
            }
        }
        cout << (i == 0? 'N':'A') << endl;
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