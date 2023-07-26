class Solution {
public:
    int n;
    int dp[30000][2];
    int solve(vector<int>&prices,int ind,bool buy){
        if(ind>=n)return 0;
        
        int profit=0;
        
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        
        if(buy){
            int take=solve(prices,ind,false)-prices[ind];
            int not_take=solve(prices,ind+1,buy);
            profit=max({profit,take,not_take});
        }else{
            int sell=solve(prices,ind+1,true)+prices[ind];
            int not_sell=solve(prices,ind+1,false);
            profit=max({profit,sell,not_sell});
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        n=prices.size();
        bool buy=true;
        return solve(prices,0,buy);
    }
};