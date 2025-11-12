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
    int n; cin >> n;
    vector<int> x(n);
    bool yay = false, odd = false;
    F0R(i, n) {
        cin >> x[i];
        if(i == 0) {
            odd = x[i]%2==1;
        } else {
            if(!yay && (odd && x[i]%2 == 0) || (!odd && x[i]%2 == 1)) {
                yay = true;
            }
        }
    }

    if(yay) sort(all(x));

    trav(a, x) cout << a << ' ';
    cout << endl;

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