class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = (int)costs.size()/2;
        vector<pair<int, int>> a;
        for(int i = 0; i < (int)costs.size(); i++) {
            a.push_back(make_pair(costs[i][1]-costs[i][0], i));
        }
        sort(a.begin(), a.end());

        long long ans = 0;
        int x = 0;
        for(auto& v : a) {
            if(x < n)  {
                ans += costs[v.second][1];
            } else {
                ans += costs[v.second][0];
            }
            x++;
        }
        return ans;
    }
};