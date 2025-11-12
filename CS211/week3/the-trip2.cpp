#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> bags(1e4+5);
map<int, int> sizes;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    // read n until end of file or n is 0
    while(cin >> n && n != 0) {
        k = -1;
        sizes.clear();
        for(int i = 0; i < n; i++) {
            // keep track of how many bags of each size we have
            cin >> bags[i];
            sizes[bags[i]]++;
            k = max(k, sizes[bags[i]]);
        }

        // helper variables to output answer
        int row = 0;
        vector<vector<int>> output(k+1);

        for(auto it = sizes.begin(); it != sizes.end();) {

            // keep adding bags to each row, distributing evenly
            output[row].push_back(it->first);
            it->second--;

            // advance row
            row++;
            row %= k;

            // if no more bags of current size, move to next size
            if(it->second == 0) it++;
        }

        // print contents of output
        cout << k << '\n';
        for(auto& v : output) {
            for(auto& x : v) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}