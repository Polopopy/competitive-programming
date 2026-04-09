/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    int n, k; 
    if (!(cin >> n >> k)) return;
    
    vector<ll> skills(k);
    for(int i = 0; i < k; ++i) cin >> skills[i];
    sort(skills.begin(), skills.end(), greater<ll>());
    
    vector<int> p(n, -1), depth(n, 0), deep(n, -1), best(n, -1);
    vector<bool> leaf(n, true);
    
    for(int i = 1; i < n; ++i) {
        cin >> p[i];
        leaf[p[i]] = false;
        depth[i] = depth[p[i]] + 1;
    }
    
    for(int i = 0; i < n; ++i) {
        if(leaf[i]) {
            deep[i] = depth[i];
            best[i] = i;
        }
    }
    
    for(int i = n - 1; i >= 1; --i) {
        if(deep[i] > deep[p[i]]) {
            deep[p[i]] = deep[i];
            best[p[i]] = best[i];
        }
    }
    
    vector<int> path(n, 0);
    for(int i = 1; i < n; ++i) path[best[i]]++;
    
    sort(path.begin(), path.end(), greater<int>());
    
    ll ans = 0;
    for(int i = 0; i < k; ++i) {
        ans += skills[i]*path[i];
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    solve();

    return 0;
}