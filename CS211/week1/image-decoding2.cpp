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
    bool first = true;

    // read number of scanlines until 0 or end of file
    while(cin >> n && n != 0) {

    	// if not first, add extra newline
    	if(!first) cout << '\n';
    	first = false;

    	// track expected line length and whether current image causes an error
    	int expected_line_length = -1;
    	bool invalid = false;

    	for(int i = 0; i < n; i++) {
    		int current_line_length = 0;
    		char c;
    		cin >> c;

    		// initialize dot to true if starting character is a dot
    		bool dot = (c == '.');

    		int current_number;
    		while(cin >> current_number) {
    			current_line_length += current_number;

    			// output current_number of dots if dot is true and hashes if dot is false
    			cout << string(current_number, (dot? '.':'#'));

    			// flip value of dot for next run input
    			dot = !dot;

    			// break if we reach a newline
    			if(cin.peek() == '\n') break;
    		}
            
    		// if this is the first line, initialize expected line length
    		if(expected_line_length == -1) {
                expected_line_length = current_line_length;
            }

            // check if the current line length does not align with the expected line length
    		if(expected_line_length != current_line_length) {
                invalid = true;
            }
            cout << '\n';
    	}

    	if(invalid) cout << "Error decoding image" << '\n';
    }
    return 0;
}