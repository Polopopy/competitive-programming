/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// trie node struct
struct node {
    int count = 0;
    vector<node*> children = vector<node*>(26);
};

// update trie
void modify(node* root, string name, int delta) {
    node* curr = root;
    curr->count += delta;
    for(char c : name) {
        // for each character, move to next node
        int i = c-'A';
        if(!curr->children[i]) curr->children[i] = new node();
        curr = curr->children[i];
        // modify counter variable with delta (can be -1 or 1)
        curr->count += delta;
    }
}

// count number of strings greater than or equal to prefix
ll count(node* root, string prefix) {
    ll ret = 0;
    node* curr = root;
    bool yay = true;
    for(char c : prefix) {
        int i = c-'A';
        // loop through all children greater than the next letter and count them
        for(int j = i+1; j < 26; ++j) {
            if(curr->children[j]) ret += curr->children[j]->count;
        }
        if(!curr->children[i]) {
            // if the there are no more nodes satisfying the prefix, break
            yay = false;
            break;
        }
        curr = curr->children[i];
    }
    // if there are nonzero strings that fully filled prefix, add all the rest that extend it
    if(yay) ret += curr->count;
    return ret;
}

void solve() {
    node* boys = new node();
    node* girls = new node();
    unordered_map<string, bool> guys, gals;

    int op;
    while(cin >> op && op != 0) {
        if(op == 1) {
            string s;
            int gender;
            cin >> s >> gender;
            // depending on gender, modify correct trie
            if(gender == 1) {
                modify(boys, s, 1);
                guys[s] = true;
            } else {
                modify(girls, s, 1);
                gals[s] = true;
            }
        }
        if(op == 2) {
            string s; cin >> s;
            // check which gender the string is in and delete it
            if(guys[s]) {
                modify(boys, s, -1);
                guys.erase(s);
            } else {
                modify(girls, s, -1);
                gals.erase(s);
            }
        }
        if(op == 3) {
            string l, r;
            int gender;
            cin >> l >> r >> gender;
            ll ans = 0;
            if(gender == 0) {
                // for both, query both the girl and boy trie
                ans = (count(boys, l) - count(boys, r)) + (count(girls, l) - count(girls, r));
            }
            if(gender == 1) {
                // query for boys between [l, r)
                ans = (count(boys, l) - count(boys, r));
            }
            if(gender == 2) {
                // query for girls between [l, r)
                ans = (count(girls, l) - count(girls, r));
            }
            cout << ans << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}