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
const int mod = 1e7+6;

void floyd_warshall(vector<vector<int>>& d){
    int n = sz(d);
    F0R(k,n) F0R(i,n) if (d[i][k] < inf) F0R(j,n) if (d[k][j] < inf)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

void solve() {
    int n, m, q;
    while(cin >> n >> m >> q && (n != 0 || m != 0 || q != 0)) {
        vector<vector<int>> d(n, vector<int>(n, inf));
        F0R(i, n) d[i][i] = 0;
        F0R(i, m) {
            int a, b, w;
            cin >> a >> b >> w;
            d[a][b] = min(d[a][b], w);
        }

        floyd_warshall(d);

        F0R(i, q) {
            int a, b; cin >> a >> b;
            if(d[a][b] == inf) {
                cout << "Impossible" << endl;
            } else {
                bool neg = false;
                F0R(j, n) {
                    if(d[a][j] != inf && d[j][j] < 0 && d[j][b] != inf) {
                        neg = true;
                        break;
                    }
                }
                if(neg) {
                    cout << "-Infinity" << endl;
                } else {
                    cout << d[a][b] << endl;
                }
            }
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    // freopen("filename.in", "r", stdin);
    // freopen("filename.out", "w", stdout);

    // int T;
    // cin >> T;
    // while(T--) {
    //     solve();
    // }

    solve();
}