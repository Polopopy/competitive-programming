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

const int maxn = 503;
const int inf = 1e9+2;
const int mod = 2e9;

void solve() {
    int r, c, n; cin >> r >> c >> n;
    vector<pair<int, int>> tower(n);
    F0R(i, n) {
        cin >> tower[i].f >> tower[i].s;
        tower[i].f--;
        tower[i].s--;
    }

    deque<pair<pair<int, int>, int>> dq;

    vector<vector<int>> a1(r, vector<int>(c)), a2(r, vector<int>(c));    
    F0R(i, n) dq.pb({{tower[i].f, tower[i].s}, i+1});

    while(!dq.empty()) {
        auto a = dq.front();
        dq.pop_front();
        if(a1[a.f.f][a.f.s] == 0) {
            a1[a.f.f][a.f.s] = a.s;
        } else if(a1[a.f.f][a.f.s] != a.s && a2[a.f.f][a.f.s] == 0) {
            a2[a.f.f][a.f.s] = a.s;
        } else {
            continue;
        }

        if(a.f.f > 0 && (a1[a.f.f-1][a.f.s] == 0 || a1[a.f.f-1][a.f.s] != a.s && a2[a.f.f-1][a.f.s] == 0)) dq.pb({{a.f.f-1, a.f.s}, a.s});
        if(a.f.s > 0 && (a1[a.f.f][a.f.s-1] == 0 || a1[a.f.f][a.f.s-1] != a.s && a2[a.f.f][a.f.s-1] == 0)) dq.pb({{a.f.f, a.f.s-1}, a.s});
        if(a.f.f < r-1 && (a1[a.f.f+1][a.f.s] == 0 || a1[a.f.f+1][a.f.s] != a.s && a2[a.f.f+1][a.f.s] == 0)) dq.pb({{a.f.f+1, a.f.s}, a.s});
        if(a.f.s < c-1 && (a1[a.f.f][a.f.s+1] == 0 || a1[a.f.f][a.f.s+1] != a.s && a2[a.f.f][a.f.s+1] == 0)) dq.pb({{a.f.f, a.f.s+1}, a.s});
    }

    F0R(i, r) {
        F0R(j, c) cout << a1[i][j] << ' ';
        cout << endl;
    }

    F0R(i, r) {
        F0R(j, c) cout << a2[i][j] << ' ';
        cout << endl;
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