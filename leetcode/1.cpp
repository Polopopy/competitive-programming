#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)
#define R0F(i, a) ROF(i, a, 0)
#define trav(a,x) for (auto& a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define ins insert
#define endl '\n'

// O(n logn)
vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> seen;
    F0R(i, sz(nums)) {
        if(seen.find(target - nums[i]) != seen.end()) {
            return {seen[target - nums[i]], i};
        }
        seen[nums[i]] = i;
    }
    return {-1, -1};
}