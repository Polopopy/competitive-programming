#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)
#define R0F(i, a) ROF(i, a, 0)
#define trav(a, x) for (auto &a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define ins insert
#define endl '\n'

const int maxn = 1e5 + 5;
const int inf = 2e9 + 5;
const int mod = 2e9;

void solve()
{
    int n, k;
    cin >> n >> k;
    int a = 0, b = 0, c = 0, d = 0;
    int y = inf, z = inf, p = inf;
    F0R(i, n)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
            a++;
        if (x % 3 == 0)
            b++;
        if (x % 4 == 0)
            d++;
        if (x % 5 == 0)
            c++;
        y = min(y, 3 - (x % 3));
        z = min(z, 5 - (x % 5));
        p = min(p, 4 - (x % 4));
    }

    if (k == 2)
    {
        if (a > 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    else if (k == 4)
    {
        if (a > 1 || d > 0)
        {
            cout << 0 << endl;
        }
        else
        {
            if (a > 0)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << min(p, 2) << endl;
            }
        }
    }
    else if (k == 5)
    {
        if (c > 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << z << endl;
        }
    }
    else

        if (k == 3)
    {
        if (b > 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << y << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    // freopen("filename.in", "r", stdin);
    // freopen("filename.out", "w", stdout);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    // solve();
}