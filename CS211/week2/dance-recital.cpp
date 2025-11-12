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

const int maxn = 10;
const int inf = 1e9+2;
const int mod = 2e9;

vector<int> a(maxn);
vector<string> b(maxn);
vector<unordered_set<char>> c(maxn);
vector<vector<int>> why(maxn, vector<int>(maxn));

void solve() {
    iota(all(a), 0);
    int n; cin >> n;
    int ans = inf;
    F0R(i, n) cin >> b[i];

    F0R(i, n) {
        trav(x, b[i]) {
            c[i].insert(x);
            if(i != 0) {
                F0R(j, i) {
                    if(c[j].find(x) != c[j].end()) {
                        why[i][j]++;
                        why[j][i]++;
                    }
                }
            }
        }
    }

    do {
        int tmp = 0;
        FOR(i, 1, n) {
            tmp += why[a[i]][a[i-1]];
        }
        ans = min(ans, tmp);
    } while(next_permutation(a.begin(), a.begin()+n));

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