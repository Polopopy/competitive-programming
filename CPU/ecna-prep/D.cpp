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

vector<int> dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n+2, vector<char>(m+2, '.'));
    vector<vector<int>> ans(n+2, vector<int>(m+2, inf));

    FOR(i, 1, n+1) FOR(j, 1, m+1) cin >> a[i][j];

    int big = 0;

    FOR(balls, 1, n/2+3) {
        FOR(i, 1, n+1) {
            FOR(j, 1, m+1) {
                if(a[i][j] == 'T' && ans[i][j] == inf) {
                    int cm = inf;
                    F0R(rep, 4) {
                        if(balls > 1) {
                            if(ans[i+dx[rep]][j+dy[rep]] == balls-1) {
                                ans[i][j] = balls;
                                big = max(big, balls);
                                break;
                            }
                        } else {
                            if(a[i+dx[rep]][j+dy[rep]] == '.') {
                                ans[i][j] = 1;
                                big = max(big, 1);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    int rep = (big >= 10? 3:2);
    FOR(i, 1, n+1) {
        FOR(j, 1, m+1) {
            if(ans[i][j] == inf) {
                cout << string(rep, '.');
            } else {
                int d = 0, v = ans[i][j];
                while(v > 0) {
                    v /= 10;
                    d++;
                }
                cout << string(rep-d, '.') << ans[i][j];
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