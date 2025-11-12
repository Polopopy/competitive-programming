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
    int n;
    while(cin >> n) {
        int r, a, b, c;
        cin >> r >> a >> b >> c;

        vector<set<int>> adj(n);
        vector<bool> vis(n);

        F0R(i, n) {
            r = (r*a+b)%c;
            int x = r%n;
            r = (r*a+b)%c;
            int y = r%n;

            if(x == y) {
                r = (r*a+b)%c;
                x = r%n;
                r = (r*a+b)%c;
                y = r%n;
            }
            
            adj[x].insert(y);
            adj[y].insert(x);
        }

        int ans = 0;
        vector<int> cnt(n+1);

        F0R(i, n) {
            if(!vis[i]) {
                deque<int> td;
                td.clear();
                td.pb(i);
                int curr = 0;
                while(!td.empty()) {
                    int x = td.back();
                    td.pop_back();

                    if(vis[x]) continue;

                    curr++;
                    vis[x] = true;
                    trav(nx, adj[x]) {
                        if(!vis[nx]) td.pb(nx);
                    }
                }
                ans++;
                cnt[curr]++;
            }
        }

        cout << ans << ' ';
        ROF(i, n, 1) {
            if(cnt[i] > 1) {
                cout << i << "x" << cnt[i] << ' ';
            } else if(cnt[i] == 1) {
                cout << i << ' ';
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