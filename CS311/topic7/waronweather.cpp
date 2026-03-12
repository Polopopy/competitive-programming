/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct pt {
    double x, y, z;
};

// square function because built in is SLOW
double sq(double x) {
    return x*x;
}

void solve() {
    int n, m;
    while(cin >> n >> m && n != 0) {
        vector<pt> sats(n), tgts(m);
        vector<bool> visited(m);
        for(auto& a : sats) cin >> a.x >> a.y >> a.z;
        for(auto& a : tgts) cin >> a.x >> a.y >> a.z;

        int ans = 0;
        for(auto& a : sats) {
            // find length of tangent line segment to earth's surface
            double big = (sq(a.x)+sq(a.y)+sq(a.z)) - sq(20000/3.14159265358979323846264338327950288419716939937);
            for(int i = 0; i < m; ++i) {
                // for each satellite, check if it's inside the view of our current satellite
                // AKA if it's within the length of the tangent segment to earth's surface
                if(!visited[i] && (sq(a.x-tgts[i].x) + sq(a.y-tgts[i].y) + sq(a.z-tgts[i].z)) <= big) {
                    // update and avoid double counting
                    visited[i] = true;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}