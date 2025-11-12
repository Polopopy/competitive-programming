#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, current_layer, previous_layer;
    cin >> n >> previous_layer;

    // we need two walls immediately unless the top layer is empty
    long long answer = previous_layer+2;
    if(previous_layer == 0) answer--;

    // if current layer is too big, we need to make more space and add a wall to the existing structure
    for(int i = 0; i < n-1; i++) {
        cin >> current_layer;
        if(current_layer > previous_layer) answer += (current_layer-previous_layer+1);
        previous_layer = current_layer;
    }

    cout << answer << '\n';

    return 0;
}