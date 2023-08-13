class Solution {
public:
    int n;
    vector<int>dp;
    bool solve(vector<int>&nums,int index){
        if(index>=n)return true;
        if(index==n-1)return false;
        if(index==n-2){
            return nums[n-2]==nums[n-1];
        }
        if(dp[index]!=-1)return dp[index];
        bool a=false;
        if(nums[index]==nums[index+1]){
            a=solve(nums,index+2);
        }
        bool b=false;
        if(nums[index]==nums[index+1] && nums[index+1]==nums[index+2]){
            b=solve(nums,index+3);
        }
        bool c=false;
        if(nums[index]+1==nums[index+1] && nums[index+1]+1==nums[index+2]){
            c=solve(nums,index+3);
        }
        return dp[index]=(a||b||c);
    }
    bool validPartition(vector<int>& nums) {
        n=nums.size();
        dp.resize(n,-1);
        return solve(nums,0);
    }
};