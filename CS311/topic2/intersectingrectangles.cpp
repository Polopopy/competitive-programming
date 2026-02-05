/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct pt {
    int pos;
    int diff;
    int x1, x2;

    bool operator <(const pt& o) const {
        if(pos != o.pos) return pos < o.pos;
        if(diff != o.diff) return diff < o.diff;
        return x1 < o.x1;
    }
};

void solve() {
    int n; cin >> n;
    int ans = 0;
    multiset<pt> td;
    set<pair<int, int>> active;

    for(int i = 0; i < n; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        td.insert({b, 1, a, c});
        td.insert({d, -1, a, c});
    }

    for(auto& p : td) {
        if (p.diff == -1) {
            auto it = active.find({p.x1, p.x2});
            if(it != active.end()) active.erase(it);
        }

        auto it = active.lower_bound({p.x1, -2e9});

        if(it != active.end()) {
            if (it->first < p.x2) {
                ans = 1;
                break;
            }
        }

        if(it != active.begin()) {
            auto prev_it = prev(it);
            if (prev_it->second > p.x1) {
                bool nested = (prev_it->first < p.x1 && prev_it->second > p.x2);
                if (!nested) {
                    ans = 1;
                    break;
                }
            }
        }

        if (p.diff == 1) {
            active.insert({p.x1, p.x2});
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}