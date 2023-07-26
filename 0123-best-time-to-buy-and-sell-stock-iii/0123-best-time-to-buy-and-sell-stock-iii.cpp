class Solution {
public:
    int n;
    int dp[100000][2][2];
    int solve(vector<int>&prices,int ind,bool buy,int c){
        if(ind>=n||c>=2)return 0;
        int profit=0;
        if(dp[ind][buy][c]!=-1)return dp[ind][buy][c];
        if(buy){
            int take=solve(prices,ind+1,false,c)-prices[ind];
            int not_take=solve(prices,ind+1,buy,c);
            profit=max({profit,not_take,take});
        }else{
            int sell=solve(prices,ind+1,true,c+1)+prices[ind];
            int notsell=solve(prices,ind+1,buy,c);
            profit=max({profit,sell,notsell});
        }
        return dp[ind][buy][c]=profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        n=prices.size();
        bool buy=true;
        return solve(prices,0,buy,0);
    }
};