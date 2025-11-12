/*

Author: Ray Han
It is ok to share my code anonymously for educational purposes

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;

    // read until n is 0 or we reach the end of file
    while(cin >> n && n != 0) {
    	// two piles
    	int pile1 = 0, pile2 = 0;

    	for(int i = 0; i < n; i++) {
    		string operation;
    		int reps;
    		cin >> operation >> reps;

    		if(operation == "DROP") {
    			// always drop new plates on pile1
    			cout << "DROP 1 " << reps << '\n';
    			pile1 += reps;
    		} else {
    			if(pile2 >= reps) {
    				// if we have enough plates in pile2, take what we need
    				cout << "TAKE 2 " << reps << '\n';
    				pile2 -= reps;
    			} else {
    				// if we don't have enough plates
    				if(pile2 != 0) {
    					// take as many as we can
    					cout << "TAKE 2 " << pile2 << '\n';
    					reps -= pile2;
                    }

					// move ALL the plates over from pile1
					cout << "MOVE 1->2 " << pile1 << '\n';
					pile2 = pile1;
					pile1 = 0;

					// take the rest that we need
					cout << "TAKE 2 " << reps << '\n';
    			}
    		}
    	}
    	cout << '\n';
    }

    return 0;
}