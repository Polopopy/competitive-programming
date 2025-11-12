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
    vector<int> js(n);
    F0R(i, n) cin >> js[i];

    int c = js[n-1]/3;
    int a = js[0]/3;
    
    FOR(b, a, c+1) {
        bool yay = true;
        trav(x, js) {
            if(x-a-b-c == 0 || x-a-a-b == 0 || x-a-a-c == 0 || x-a-a-a == 0 ||
                            x-b-b-a == 0 || x-b-b-c == 0 || x-b-b-b == 0 ||
                            x-c-c-a == 0 || x-c-c-b == 0 || x-c-c-c == 0) {
            } else {
                yay = false;
            }
        }
        if(yay) {
            cout << a << ' ' << b << ' ' << c << endl;
            break;
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