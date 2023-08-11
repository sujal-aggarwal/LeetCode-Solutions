class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(int amount,int index,vector<int>&coins){
        if(index>=n)return 0;
        if(amount==0)return 1;
        if(dp[amount][index]!=-1)return dp[amount][index];
        int ans=0;
        int take=0;
        if(coins[index]<=amount)
            take=solve(amount-coins[index],index,coins);
        int not_take=solve(amount,index+1,coins);
        return dp[amount][index]=take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        dp.resize(amount+1,vector<int>(n+1,-1));
        return solve(amount,0,coins);
    }
};