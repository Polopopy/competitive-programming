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
    int ans = 0;
    vector<int> x(n);
    F0R(i, n) cin >> x[i];

    FOR(i, 1, n-1) {
        int tmp = 1;
        bool valid = true;
        int a = i-1, b = i+1;
        while(a >= 0 && b < n) {
            if(x[a] == x[b] && x[a] < x[a+1] && x[b] < x[b-1]) {
                tmp += 2;
            } else {
                valid = false;
                break;
            }
            a--;
            b++;
        }
        if(tmp >= 3) {
            ans = max(ans, tmp);
        }
    }

    cout << (ans==0? -1:ans) << endl;
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