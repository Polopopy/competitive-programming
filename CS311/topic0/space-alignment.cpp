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

void solve() {
    int n; cin >> n;
    int lvl = 0, ans = -1;
    map<int, set<pair<int, int>>> td;
    bool done = false;
    F0R(i, n) {
        string s; cin >> s;
        int a = 0, b = 0;
        trav(c, s) {
            if(c == '{') {
                if(lvl > 0) td[lvl].insert(mp(a, b));
                lvl++;
            } else if(c == '}') {
                lvl--;
                if(lvl > 0) td[lvl].insert(mp(a, b));
            } else if(c == 's') {
                a++;
            } else if(c == 't') {
                b++;
            }
        }
    }

    FOR(i, 1, 1001) {
        int tmp = -1;
        bool valid  = true;
        trav(x, td) {
            trav(curr, x.s) {
                int res = curr.f + curr.s*i;
                if(tmp == -1) {
                    tmp = res;
                } else {
                    if(tmp*x.f != res) {
                        valid = false;
                        break;
                    }
                }
            }
            if(!valid) break;
        }
        if(valid) {
            ans = i;
            break;
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