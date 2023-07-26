class Solution {
public:
    int n;
    vector<vector<vector<int>>>dp;
    int solve(vector<int>&prices,int ind,int buy,int c){
        if(ind>=n||c<=0)return 0;
        int profit=0;
        if(dp[ind][buy][c]!=-1)return dp[ind][buy][c];
        if(buy){
            int take=solve(prices,ind+1,0,c)-prices[ind];
            int not_take=solve(prices,ind+1,buy,c);
            profit=max({profit,not_take,take});
        }else{
            int sell=solve(prices,ind+1,1,c-1)+prices[ind];
            int notsell=solve(prices,ind+1,buy,c);
            profit=max({profit,sell,notsell});
        }
        return dp[ind][buy][c]=profit;
    }
    int maxProfit(int k,vector<int>& prices) {
        dp.resize(1000,vector(2,vector<int>(k+1,-1)));
        n=prices.size();
        return solve(prices,0,1,k);
    }
};