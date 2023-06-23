class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size(), ans = 1;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int diff = nums[j] - nums[i];
                
                if(mp.find(diff) == mp.end())
                    mp[diff] = vector<int> (1001, 1);
                
                mp[diff][i] = max(mp[diff][i], mp[diff][j] + 1);
                ans = max(ans, mp[diff][i]);
            }
        }
        return ans;
    }
};