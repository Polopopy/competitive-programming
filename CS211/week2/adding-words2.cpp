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
	
	string command;
	unordered_map<string, int> word_to_num;
	unordered_map<int, string> num_to_word;

	while(cin >> command) {
		if(command == "def") {
			string key;
			int value;
			cin >> key >> value;

			// if this definition existed before, delete the old mapping
			if(word_to_num.find(key) != word_to_num.end()) {
				num_to_word.erase(word_to_num[key]);
			}

			// save mapping
			word_to_num[key] = value;
			num_to_word[value] = key;
		} else if(command == "calc") {
			bool unknown = false;

			// operation = 0 means addition and 1 means subtraction
			int answer = 0, operation = 0;
			string current_word;

			// process calculations one word at a time
			while(cin >> current_word) {
				// if we reach the end of the command, break
				if(cin.peek() == '\n') break;
				if(current_word[0] == '=') break;

				// if the word is an operator, save it and move on
				if(current_word[0] == '+') {
					cout << " + ";
					operation = 0;
					continue;
				} else if(current_word[0] == '-') {
					cout << " - ";
					operation = 1;
					continue;
				}

				// if the word is NOT an operator
				cout << current_word;

				if(!unknown) {
					// if the word has no associated value, set unknown to true
					if(word_to_num.find(current_word) == word_to_num.end()) {
						unknown = true;
					} else {
						// otherwise, update the answer to the calculation
						//   (operation? -1:1) = -1 if (operation > 0) and 1 if (operation <= 0)
						answer += (operation? -1:1) * word_to_num[current_word];
					}
				}
			}
			// after finishing all computations on the line, output
			cout << " = ";
			if(unknown || num_to_word.find(answer) == num_to_word.end()) {
				cout << "unknown\n";
			} else {
				cout << num_to_word[answer] << '\n';
			}
		} else {
			// neither "def" or "calc" means we must clear our references
			word_to_num.clear();
			num_to_word.clear();
		}
	}

	return 0;
}