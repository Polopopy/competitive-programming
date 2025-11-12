#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, answer;
double longest;
vector<double> nurse_pos(1e6+2);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.setf(std::ios::fixed);
    cout << std::setprecision(1);

    cin >> n;

    // compute longest time to reach any point and save nurse positions
    for(int i = 0; i < n; i++) {
        cin >> nurse_pos[i];
        if(i == 0) {
            // full value for start to first nurse
            longest = nurse_pos[i];
        } else {
            // half for gaps between nurses
            longest = max(longest, (nurse_pos[i]-nurse_pos[i-1])/2);
        }

        // full value for final nurse to end
        if(i == n-1) longest = max(longest, 5000000 - nurse_pos[i]);
    }

    if(n != 1) {
        // binary search to find start (farthest nurse from the start that distance does not exceed longest)
        // all nurses before start can be removed
        auto it = upper_bound(nurse_pos.begin(), nurse_pos.begin()+n, longest);
        int start = 0;
        if(it != nurse_pos.begin()) start = (--it)-nurse_pos.begin();

        // same thing for the end (farthest nurse from the end that distance does need exceed longest)
        // all nurses after end can be removed
        it = lower_bound(nurse_pos.begin(), nurse_pos.begin()+n, 5000000-longest);
        int end = n-1;
        if(it != nurse_pos.begin()+n) end = it-nurse_pos.begin();

        int previous_nurse = start;

        // answer starts counting the nurses removed before start and after end
        answer = start + (n-end-1);

        while(previous_nurse < end) {
            // binary search to find the next removable nurse (farthest that does not exceed current+longest)
            it = --upper_bound(nurse_pos.begin()+previous_nurse+1, 
                               nurse_pos.begin()+end+1, 
                               nurse_pos[previous_nurse]+2*longest);

            int current_nurse = it-nurse_pos.begin();
            answer += (current_nurse-previous_nurse-1);
            previous_nurse = current_nurse;
            if(current_nurse == end) break;
        }
    }

    cout << longest << ' ' << answer << '\n';

    return 0;
}