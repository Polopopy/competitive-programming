/*

Author: Ray Han
It is ok to share my code anonymously for educational purposes

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// maxn is the largest possible n + 5
static const int maxn = 25;

vector<int> key(maxn);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    // read values of n until end of file or n = 0
    while(cin >> n && n != 0) {

        // read key
        for(int i = 0; i < n; i++) {
            cin >> key[i];
            key[i]--;
        }
        cin.ignore();

        // read message
        string message;
        getline(cin, message);
        int m = (int)message.length();

        // compute number of times we will cycle through key throughout the given message
        //  (rounded up)
        int runs = (m+n-1) / n;
        int message_index = 0;

        cout << '\'';

        // loop through key array 'runs' times
        for(int i = 0; i < runs; i++) {
            for(int j = 0; j < n; j++) {

                // compute character position to print in original message
                int target_index = message_index + key[j];
                
                if (target_index < m) {
                    cout << message[target_index];
                } else {
                    // if out of bounds, print whitespace
                    cout << ' ';
                }
            }
            message_index += n;
        }
        cout << '\'' << '\n';
    }

    return 0;
}
