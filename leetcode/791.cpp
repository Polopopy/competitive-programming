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

// O(n logn)
string customSortString(string order, string s) {
    unordered_map<char, int> x;
    F0R(i, sz(order)) x[order[i]] = i;
    sort(all(s), [&](char a, char b){return x[a] < x[b];});
    return s;
}

// O(n)
string customSortString(string order, string s) {
    map<char, int> x;
    string ret = "";
    trav(c, s) x[c]++;
    trav(c, order) {
        R0F(i, x[c]-1) ret += c;
        x[c] = 0;
    }
    trav(a, x) R0F(i, a.s-1) ret += a.f;
    return ret;
}