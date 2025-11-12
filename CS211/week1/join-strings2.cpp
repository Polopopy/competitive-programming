/*

Author: Ray Han
It is ok to share my code anonymously for educational purposes

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// maxn is the largest possible n + 5
static const int maxn = 1e5 + 5;

vector<string> strings(maxn);

// vector of pairs (index of source string, has parent)
vector<pair<vector<int>, bool>> adj(maxn);


// function to recursively print final string
void output(int start, vector<pair<vector<int>, bool>>& adj, vector<string>& strings) {

	// for each string, print it - then recursively visit the adjacent strings in order
    cout << strings[start];
    for(auto& x : adj[start].first) {
        output(x, adj, strings);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> strings[i];

    // build directed graph
    for(int i = 0; i < (n-1); i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].first.push_back(b);

        // mark whether b has a parent node
        adj[b].second = true;
    }

    // find root note to begin output
    for(int i = 0; i < n; i++) {
        if (!adj[i].second) {
            output(i, adj, strings);
            return 0;
        }
    }
}
