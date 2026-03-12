/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// splat struct to make implementation cleaner
struct splat {
    double x, y, r;
    string color;
    bool contains(double a, double b) {return ((a-x)*(a-x) + (b-y)*(b-y) <= (r*r));}
};

void solve() {
    int n; cin >> n;
    vector<splat> splats(n);
    // read each splat and populate vector of splats
    for(int i = 0; i < n; ++i) {
        double x, y, v; cin >> x >> y >> v;
        string c; cin >> c;
        splats[i] = {x, y, sqrt(v/3.1415926535), c};
    }

    int q; cin >> q;
    for(int i = 0; i < q; ++i) {
        // for each query, we start at white and apply all the paint drops
        double a, b; cin >> a >> b;
        string ans = "white";
        for(auto& x : splats) {
            // if the paint drop covers our current color, update
            if(x.contains(a, b)) {
                ans = x.color;
            }
        }
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while(T--) solve();
}