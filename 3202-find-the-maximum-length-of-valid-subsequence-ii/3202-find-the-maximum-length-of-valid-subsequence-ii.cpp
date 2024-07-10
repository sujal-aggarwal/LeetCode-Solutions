class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        for_each(nums.begin(),nums.end(),[=](int& current_value){
            current_value%=k;
        });
        int ans=0;
        for(int modulo=0;modulo<k;modulo++){
            vector<int>dp(n,1);
            unordered_map<int,int>mp;
            for(int index=0;index<n;index++){
                int curr_val=nums[index];
                if(modulo-curr_val>=0){
                    int target=modulo-curr_val;
                    if((mp.find(target))!=mp.end()){
                        int length=dp[mp[target]];
                        length++;
                        dp[index]=length;
                        ans=max(length,ans);
                    }
                }else{
                    int target=k+modulo-curr_val;
                    if((mp.find(target))!=mp.end()){
                        int length=dp[mp[target]];
                        length++;
                        dp[index]=length;
                        ans=max(length,ans);
                    }
                }
                mp[curr_val]=index;
            }
        }
        return ans;
    }
};