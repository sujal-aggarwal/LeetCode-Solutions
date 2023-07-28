class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int winner(vector<int>&nums,int i,int j){
        if(j<i){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int left=nums[i]+min(winner(nums,i+2,j),winner(nums,i+1,j-1));
        int right=nums[j]+min(winner(nums,i,j-2),winner(nums,i+1,j-1));
        return dp[i][j]=max(left,right);
    }
    bool PredictTheWinner(vector<int>& nums) {
        n=nums.size();
        dp.resize(n,vector(n,-1));
        int a=winner(nums,0,n-1);
        return a>=(accumulate(nums.begin(),nums.end(),0)-a);
    }
};