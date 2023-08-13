class Solution {
public:
    int n;
    vector<int>dp;
    bool solve(vector<int>&nums){
        if(n==2){
            return nums[0]==nums[1];
        }
        dp[n]=1;
        dp[n-1]=0;
        dp[n-2]=(nums[n-2]==nums[n-1]);
        for(int i=n-3;i>=0;i--){
            bool a=false;
            if(nums[i]==nums[i+1]){
                a=dp[i+2];
            }
            bool b=false;
            if(nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
                b=dp[i+3];
            }
            bool c=false;
            if(nums[i]+1==nums[i+1] && nums[i+1]+1==nums[i+2]){
                c=dp[i+3];
            }
            dp[i]=(a||b||c);
        }
        return dp[0];
    }
    bool validPartition(vector<int>& nums) {
        n=nums.size();
        dp.resize(n+1,-1);
        return solve(nums);
    }
};