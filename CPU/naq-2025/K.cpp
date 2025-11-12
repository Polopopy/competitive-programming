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
// #define endl '\n'

const int maxn = 1e5+5;
const int inf = 1e9+2;
const int mod = 2e9;

void hit(int r, int c) {
    bool x;
    cout << "? " << r << ' ' << c-1 << endl;
    cin >> x;
    if(x) {
        cout << "? " << r+1 << ' ' << c-1 << endl;
        cin >> x;
        if(x) {
            cout << "! " << r << ' ' << c-1 << endl;
            exit(0);
        } else {
            cout << "! " << r-1 << ' '  <<  c-1 << endl;
            exit(0);
        }
    } else {
        cout << "? " << r+1 << ' ' << c+1 << endl;
        cin >> x;
        if(x) {
            cout << "! " << r << ' ' << c << endl;
            exit(0);
        } else {
            cout << "! " << r-1 << ' ' << c << endl;
            exit(0);
        }
    }
}

void solve() {
    bool x;
    cout << "? 2 2" << endl;
    cin >> x;
    if(x) {
        hit(2, 2);
    } else {
        cout << "? 4 2" << endl;
        cin >> x;
        if(x) {
            hit(4, 2);
        } else {
            cout << "? 2 4" << endl;
            cin >> x;
            if(x) {
                hit(2, 4);
            } else {
                cout << "? 3 4" << endl;
                cin >> x;
                bool y;
                cout << "? 4 3" << endl;
                cin >> y;
                if(x && y) {
                    cout << "! 3 3" << endl;
                    exit(0);
                } else if(x && !y) {
                    cout << "! 3 4" << endl;
                    exit(0);
                } else if(y && !x) {
                    cout << "! 4 3" << endl;
                    exit(0);
                } else {
                    cout << "! 4 4" << endl;
                    exit(0);
                }
            }
        }
    }
}

int main() {
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