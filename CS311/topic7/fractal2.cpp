/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// custom point struct with basic point operations
struct pt {
    double x, y;
    pt operator+(pt p) {return {x + p.x, y + p.y};}
    pt operator-(pt p) {return {x - p.x, y - p.y};}
    pt operator*(double d) {return {x * d, y * d};}
    pt operator*(pt p) {return {x * p.x - y * p.y, x * p.y + y * p.x};}
    pt operator/(pt p) const {
        double den = p.x * p.x + p.y * p.y;
        return {(x * p.x + y * p.y) / den, (y * p.x - x * p.y) / den};
    }
};

void solve() {
    int n; cin >> n;
    vector<pt> pts(n);
    for(int i = 0; i < n; ++i) cin >> pts[i].x >> pts[i].y;
    int depth = 0;
    double f = 0.0;
    cin >> depth >> f;
    vector<double> c(n, 0.0);
    // compute distances between segments in the original
    for(int i = 0; i < n-1; ++i) c[i+1] = c[i] + hypot(pts[i+1].x - pts[i].x, pts[i+1].y - pts[i].y);
    // scale the relative distances in the original shape
    for(int i = 0; i < n; ++i) c[i] /= c[n - 1];

    pt s = pts[0];
    pt e = pts[n-1];
    pt vec = pts[n-1] - pts[0];

    while(depth--) {
        int i = 0;
        // find next segment
        while(i < n-2 && f >= c[i+1]) i++;
        // transformation calculations
        double tmp = (f - c[i]) / (c[i+1] - c[i]);
        // points for new subsegment
        pt m = (e-s) / vec;
        pt ns = s + m * (pts[i] - pts[0]);
        pt ne = s + m * (pts[i+1] - pts[0]);
        // update fractal
        s = ns;
        e = ne;
        f = tmp;
    }
    // interpolate along final segment to find final answer with remaining distance
    pt ans = s + (e - s) * f;
    cout << fixed << setprecision(8) << ans.x << ' ' << ans.y << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while(T--) solve();
}