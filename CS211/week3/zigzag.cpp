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
    int k; cin >> k;
    if(k <= 25) {
        cout << 'a' << char('a'+k) << endl;
    } else {
        int n = (k+24)/25 + 1;
        int x = k-(n-3)*25;
        x = (x+1)/2;

        cout << 'a' << char('a'+x);
        F0R(i, n-3) cout << (i%2 == 0? 'a':'z');

        if((n-3)%2 == 0) {
            cout << ((k-2*x)%25==0? 'a':'b') << endl;
        } else {
            cout << ((k-2*x)%25==0? 'z':'y') << endl;
        }
    }
}

/*
// OLD SOLUTION - not great
void solve() {
    int k; cin >> k;
    int n = (k+24)/25 + 1;

    int tmp = k, prev = 1;
    cout << 'a';
    FOR(i, 1, n) {
        FOR(x, 1, 27) {
            int a = tmp-abs(x-prev);
            int b = 0;
            if(i != n-1) b += (max(26-x, x-1) + (n-i-2)*25);
            if(a >= 0 && a <= b) {
                cout << char('a'+x-1);
                tmp -= abs(x-prev);
                prev = x;
                break;
            }
        }
    }
}
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    solve();

    return 0;
}