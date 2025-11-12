#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int k;
    cin >> k;

    // special case - only need two letters
    if(k <= 25) {
    	cout << 'a' << char('a'+k) << '\n';
    } else {
    	// n is the minimum number of letters needed to achieve k given by ceil(k/25) + 1
    	int n = (k+24)/25 + 1;
    	// x is the alphabet position of the second letter in the name
    	// computed as total k minus 25 times the number of gaps after the first 3 chars
    	int x = k-(n-3)*25;
    	// x = ceiling(x/2)
    	x = (x+1)/2;

    	// always start with a, then print computed x char
    	cout << 'a' << char('a'+x);
    	// print alternating a's and z's until the last char
    	for(int i = 0; i < n-3; i++) cout << (i%2==0? 'a':'z');

    	// figure out whether last char should be a, b, z, or y
		if((n-3)%2 == 0) {
			cout << ((k-2*x)%25==0? 'a':'b') << '\n';
		} else {
			cout << ((k-2*x)%25==0? 'z':'y') << '\n';
		}
    }

    return 0;
}