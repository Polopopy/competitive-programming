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

const int maxn = 1e6+5;
const int inf = 1e9+2;
const int mod = 2e9;

int n, ans;
double m;
vector<double> x(maxn);

void solve() {
    cin >> n;
    F0R(i, n) {
        cin >> x[i];

        if(i == 0) {
            m = x[i];
        } else {
            m = max(m, (x[i]-x[i-1])/2);
        }

        if(i == n-1) m = max(m, 5000000.0-x[i]);
    }

    if(n != 1) {

        auto it = upper_bound(x.begin(), x.begin()+n, m);
        int start = 0;
        if(it != x.begin()) start = (--it)-x.begin();

        it = lower_bound(x.begin(), x.begin()+n, (5000000-m));
        int end = n-1;
        if(it != x.begin()+n) end = it-x.begin();

        int prev = start;
        ans = start + (n-end-1);

        while(prev < end) {
            it = --upper_bound(x.begin()+prev+1, x.begin()+end+1, x[prev]+2*m);
            int curr = it-x.begin();
            ans += (curr-prev-1);
            prev = curr;
            if(curr == end) break;
        }
    }

    cout << m << ' ' << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cout.setf(std::ios::fixed);
    cout << std::setprecision(1);

    solve();

    return 0;
}