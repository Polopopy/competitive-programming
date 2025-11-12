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

vector<vector<int>> moves = {
    {1,2,4},{1,3,6},
    {2,4,7},{2,5,9},
    {3,5,8},{3,6,10},
    {4,2,1},{4,5,6},{4,7,11},{4,8,13},
    {5,8,12},{5,9,14},
    {6,3,1},{6,5,4},{6,9,13},{6,10,15},
    {7,4,2},{7,8,9},
    {8,5,3},{8,9,10},
    {9,5,2},{9,8,7},
    {10,6,3},{10,9,8},
    {11,7,4},{11,12,13},
    {12,8,5},{12,13,14},
    {13,8,4},{13,9,6},{13,12,11},{13,14,15},
    {14,9,5},{14,13,12},
    {15,10,6},{15,14,13}
};

map<int, pair<int,int>> n2p = {
    {1,{0,0}},
    {2,{1,0}}, {3,{1,1}},
    {4,{2,0}}, {5,{2,1}}, {6,{2,2}},
    {7,{3,0}}, {8,{3,1}}, {9,{3,2}}, {10,{3,3}},
    {11,{4,0}}, {12,{4,1}}, {13,{4,2}}, {14,{4,3}}, {15,{4,4}}
};

bool yay(int mv, vector<vector<string>> &b) {
    auto x = moves[mv];
    auto a = n2p[x[0]];
    auto m = n2p[x[1]];
    auto c = n2p[x[2]];

    if (b[a.f][a.s] != "__" && b[m.f][m.s] != "__" && b[c.f][c.s] == "__") {
        b[c.f][c.s] = b[a.f][a.s];
        b[a.f][a.s] = "__";
        b[m.f][m.s] = "__";
        return true;
    }

    return false;
}

bool yippee(vector<vector<string>> &b, string t) {
    int cnt = 0;
    string last = "";
    FOR(i, 0, 5) {
        FOR(j, 0, i + 1) {
            if (b[i][j] != "__") {
                cnt++;
                last = b[i][j];
                if (cnt > 1) return false;
            }
        }
    }
    return cnt == 1 && last == t;
}

bool dfs(vector<vector<string>> &b, string t, unordered_set<string> &vis) {
    if (yippee(b, t)) return true;

    string key;
    FOR(i, 0, 5) {
        FOR(j, 0, i + 1) {
            key += b[i][j];
        }
    }

    if (vis.count(key)) return false;
    vis.insert(key);

    F0R(i, sz(moves)) {
        vector<vector<string>> nb = b;
        if (yay(i, nb)) {
            if (dfs(nb, t, vis)) return true;
        }
    }
    return false;
}

void solve() {
    string tgt;

    while (cin >> tgt && tgt != "**") {
        vector<vector<string>> b(5, vector<string>(5, "__"));
        F0R(i, 5) {
            string s;
            cin >> s;
            int k = 0;
            F0R(j, i + 1) {
                b[i][j] = s.substr(k, 2);
                k += 2;
            }
        }
        unordered_set<string> vis;
        cout << (dfs(b, tgt, vis) ? "Possible" : "Impossible") << endl;
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