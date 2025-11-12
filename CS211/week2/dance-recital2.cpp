/*

Author: Ray Han
It is ok to share my code anonymously for educational purposes

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> indices(10);
vector<string> inputs(10);
vector<unordered_set<char>> chars(10);

// initialize precompute as a 10x10 vector of 0's
vector<vector<int>> precompute(10, vector<int>(10));

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
	// populate a with 0, 1.. 9
	iota(indices.begin(), indices.end(), 0);

	int n, answer = 1e9+2;
	cin >> n;

	for(int i = 0; i < n; i++) cin >> inputs[i];

	// precompute the number of overlapping characters for every pair of strings
	for(int i = 0; i < n; i++) {
		for(auto& curr_char : inputs[i]) {
			// insert current character to the set
			chars[i].insert(curr_char);

			if(i != 0) {
				// look through all the other strings and compute number of overlaps
				for(int j = 0; j < i; j++) {
					if(chars[j].find(curr_char) != chars[j].end()) {
						precompute[i][j]++;
						precompute[j][i]++;
					}
				}
			}
		}
	}

	// for all permutations of the indices, compute number of quick changes needed
	//   using precomputed table
	do {
		int num_q_changes = 0;
		for(int i = 1; i < n; i++) {
			num_q_changes += precompute[indices[i]][indices[i-1]];
		}

		// save minimum number of quick changes
		answer = min(answer, num_q_changes);
	} while(next_permutation(indices.begin(), indices.begin()+n));

	cout << answer << '\n';

	return 0;
}