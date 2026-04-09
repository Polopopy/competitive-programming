/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
// custom sensor struct because I like custom structs now
struct sensor {
    int x, y, r;
    bool touching(sensor& o, double m) {
        double dx = x - o.x;
        double dy = y - o.y;
        double rad = r + o.r + m;
        return (dx*dx + dy*dy <= rad*rad);
    }
};

void solve() {
    int w, n; cin >> w >> n;
    vector<sensor> sensors(n);
    for(auto& x : sensors) cin >> x.x >> x.y >> x.r;
    double l = 0, r = w;
    while(abs(r-l) > 1e-6) {
        double m = l + (r-l)/2;
        // n is left wall, n+1 is right wall
        vector<vector<int>> adj(n+2);
        // build graph between sensors connected for our current m
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(sensors[i].touching(sensors[j], m)) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
            // connect to walls if they are touching by comparing distance
            if(sensors[i].x-sensors[i].r-m <= 0) {
                adj[i].push_back(n);
                adj[n].push_back(i);
            }
            if(sensors[i].x+sensors[i].r+m >= w) {
                adj[i].push_back(n+1);
                adj[n+1].push_back(i);
            }
        }

        // bfs to check if the two walls are connected
        deque<int> td;
        td.clear();
        vector<bool> visited(n+2);
        td.push_back(n);
        bool failed = false;
        while(!td.empty()) {
            int curr = td.back();
            td.pop_back();
            if(visited[curr]) continue;
            if(curr == n+1) {
                failed = true;
                break;
            }
            // visit each connected sensor
            visited[curr] = true;
            for(auto& x : adj[curr]) {
                // if we have reached the other wall, the path is fully blocked
                if(!visited[x]) {
                    td.push_back(x);
                }
            }
        }
        // update binary search
        if(!failed && !visited[n+1]) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << fixed << setprecision(6) << (l/2) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while(T--) solve();
}