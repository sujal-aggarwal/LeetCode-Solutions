class Solution {
public:
    int ans(vector<int>&arr,int t,int i,vector<vector<int>>&dp){
        if(i>=arr.size())return dp[i][t]=0;
        if(t>arr.size())return dp[i][t]=0;
        if(dp[i][t]!=-1){
            return dp[i][t];
        }
        return dp[i][t]=max((arr[i]*t)+ans(arr,t+1,i+1,dp),ans(arr,t,i+1,dp));
    }
    int maxSatisfaction(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+2,-1));
        return ans(arr,1,0,dp);
    }
};