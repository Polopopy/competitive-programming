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
    string a, b; cin >> a >> b;
    int i = 0, j = 0, n = a.length(), m = b.length();
    string ret = "";
    while(i < n && j < m) {
        if(a[i] < b[j]) {
            ret += a[i];
            i++;
        } else {
            ret += b[j];
            j++;
        }
    }

    while(i < n) {
        ret += a[i];
        i++;
    }
    while(j < m) {
        ret += b[j];
        j++;
    }

    cout << ret << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    solve();

    return 0;
}