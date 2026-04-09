/*
Author: Ray Han
It is ok to share my code anonymously for educational purposes
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// two prime bases
const ull MOD = 1e9+7;
const ull prime = 31;

const ull MOD2 = 1e9+9;
const ull prime2 = 37;

void solve() {
    int n; cin >> n;
    vector<string> words(n);
    // track all pairs of hashes we see
    set<pair<ull, ull>> seen;
    int big = 0;

    for(int i = 0; i < n; ++i) {
        cin >> words[i];
        big = max(big, (int)words[i].size());
        // build hashes for all words in both bases
        ull hash = 0, hash2 = 0;
        for(char c : words[i]) {
            hash = (hash * prime + (c-'a'+1)) % MOD;
            hash2 = (hash2 * prime2 + (c-'a'+1)) % MOD2;
        }
        // log the pairs as seen
        seen.insert({hash, hash2});
    }

    // precompute powers without overflow
    vector<ull> pows(big+1, 1), pows2(big+1, 1);
    for(int i = 1; i <= big; ++i) {
        pows[i] = (pows[i-1] * prime) % MOD;
        pows2[i] = (pows2[i-1] * prime2) % MOD2;
    }
    bool found = false;
    // precompute suffix hash arrays for the string in both bases
    for(const string& s : words) {
        int len = s.size();
        vector<ull> suff(len+1, 0), suff2(len+1, 0);
        for(int i = len-1; i >= 0; --i) {
            suff[i] = (suff[i+1] + (s[i]-'a'+1) * pows[len-1-i]) % MOD;
            suff2[i] = (suff2[i+1] + (s[i]-'a'+1) * pows2[len-1-i]) % MOD2;
        }

        // track rolling prefix in both bases
        ull pref = 0, pref2 = 0;
        bool yay = false;
        for(int i = 0; i < len; ++i) {
            // compute the hash of the string without the ith character in both bases
            ull curr = (pref * pows[len-1-i] + suff[i+1]) % MOD;
            ull curr2 = (pref2 * pows2[len-1-i] + suff2[i+1]) % MOD2;
            // if we've seen this exact pair, we can remove it
            if(seen.count({curr, curr2})) {
                yay = true;
                break;
            }
            // update rolling prefixes
            pref = (pref * prime + (s[i]-'a'+1)) % MOD;
            pref2 = (pref2 * prime2 + (s[i]-'a'+1)) % MOD2;
        }
        // if we're removing this string, print it out
        if(yay) {
            cout << s << endl;
            found = true;
        }
    }
    // no removals found
    if(!found) cout << "NO TYPOS" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    solve();
}