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
    string tmp;
    unordered_map<string, int> a;
    unordered_map<int, string> b;

    while(cin >> tmp) {
        if(tmp == "def") {
            string key; cin >> key;
            int val; cin >> val;

            if(a.find(key) != a.end()) {
                b.erase(a[key]);
            }

            a[key] = val;
            b[val] = key;
        } else if(tmp == "calc") {
            bool bad = false;
            int ans = 0, op = 0;
            string x;
            while(cin >> x) {
                if(cin.peek() == '\n') break;
                if(x[0] == '=') break;

                if(x[0] == '+') {
                    cout << " + ";
                    op = 0;
                    continue;
                } else if(x[0] == '-') {
                    cout << " - ";
                    op = 1;
                    continue;
                }

                cout << x;
                if(!bad) {
                    if(a.find(x) == a.end()) {
                        bad = true;
                    } else {
                        ans += (op? -1:1)*a[x];
                    }
                }
            }
            if(bad || b.find(ans) == b.end()) {
                cout << " = unknown" << endl;
            } else {
                cout << " = " << b[ans] << endl;
            }
        } else {
            a.clear();
            b.clear();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    // fretmpen("fname.in", "r", stdin);
    // fretmpen("fname.out", "w", stdout);

    // int T;
    // cin >> T;
    // while(T--) {
    //    solve();
    // }

    solve();

    return 0;
}