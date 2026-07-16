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

struct node {
    node *lp, *rp;
    int val;
    ll depth;
};

void solve() {
    int n; cin >> n;
    node *r = nullptr;
    ll ans = 0;
    unordered_map<int, node*> m;
    set<int> seen;

    F0R(i, n) {
        int x; cin >> x;
        if(r == nullptr) {
            r = new node();
            r->val = x;
            r->depth = 0;
            m[x] = r;
            seen.ins(x);
        } else {
            auto tmp = seen.lower_bound(x);
            if(tmp != seen.end() && x < *seen.begin()) {
                // cout << "Left " << x << endl;
                auto ptr = m[(*seen.begin())];
                ptr->lp = new node();
                ptr->lp->val = x;
                ptr->lp->depth = ptr->depth+1;
                ans += ptr->lp->depth;
                m[x] = ptr->lp;
                seen.ins(x);
            } else {
                // cout << "Right " << x << endl;
                auto b = tmp;
                --tmp;
                auto a = tmp;

                bool good = false;

                if(b == seen.end() || m[*b]->lp != nullptr || (m[*b]->depth > m[*a]->depth) && (m[*a]->rp == nullptr)) {
                    good = true;
                }

                if(good) {
                    auto ptr = m[*a];
                    ptr->rp = new node();
                    ptr->rp->val = x;
                    ptr->rp->depth = ptr->depth+1;
                    ans += ptr->rp->depth;
                    m[x] = ptr->rp;
                    seen.ins(x);
                } else {
                    auto ptr = m[*b];
                    ptr->lp = new node();
                    ptr->lp->val = x;
                    ptr->lp->depth = ptr->depth+1;
                    ans += ptr->lp->depth;
                    m[x] = ptr->lp;
                    seen.ins(x);
                }
            }
        }
        cout << ans << endl;
    }
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