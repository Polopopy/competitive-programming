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

const int maxn = 17;
const int inf = 2e9+2;
const int mod = 1e6+7;

vector<vector<int>> a(maxn, vector<int>(maxn, inf));
vector<vector<bool>> d(maxn, vector<bool>(maxn));

vector<int> dx = {-1,0,1,0}, dy = {0,1,0,-1};

void solve() {
    int n, m; cin >> n >> m;
    char c;
    FOR(i, 1, m+1) {
        cin >> c;
        d[0][i] = true;
        a[0][i] = 0;
        a[n+1][i] = 0;
    }
    FOR(i, 1, n+1) {
        FOR(j, 1, m+1) {
            cin >> a[i][j];
        }
    }
    F0R(i, m) cin >> c;

    FOR(i, 1, n+1) {
        FOR(j, 1, m+1) {
            if(a[i][j] < 0) {
                F0R(x, 4) {
                    if(a[i+dx[x]][j+dy[x]] < abs(a[i][j])) {
                        d[i][j] = true;
                    }
                }
            }
        }
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int ans = inf;
    FOR(i, 1, m+1) {
        pq.push({0, n, i});
        vector<vector<bool>> v(maxn, vector<bool>(maxn));
        while(!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            if(x[2] < 1 || x[1] > n || x[2] > m || v[x[1]][x[2]]) continue;

            v[x[1]][x[2]] = true;

            if(d[x[1]][x[2]]) {
                ans = min(ans, x[0]);
            } else {
                F0R(i, 4) {
                    int nx = x[1]+dx[i];
                    int ny = x[2]+dy[i];
                    int ns = x[0]+a[x[1]][x[2]];
                    pq.push({ns, nx, ny});
                }
            }
        }
    }
    cout << ans << endl;
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