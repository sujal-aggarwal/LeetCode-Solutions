class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> hashmap;
        int ans = 0;
        int n = grid.size();
        for (int i=0; i<n; i++) {
            hashmap[grid[i]]++;
        }
        for (int j=0; j<n; j++) {
            vector<int> curr;
            for (int i=0; i<n; i++) {
                curr.emplace_back(grid[i][j]);
            }
            ans += hashmap[curr];
        }
        return ans;
    }
};