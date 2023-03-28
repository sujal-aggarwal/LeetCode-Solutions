class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n);
        dp[n-1]=min({costs[0],costs[1],costs[2]});
        for(int i=n-2;i>=0;i--){
            int curr_day=days[i];
            int a=INT_MAX;
            int index=lower_bound(days.begin(),days.end(),curr_day+1)-days.begin();
            if(index<n){
                a=min(a,costs[0]+dp[index]);
            }else{
                a=min(a,costs[0]);
            }
            index=lower_bound(days.begin(),days.end(),curr_day+7)-days.begin();
            if(index<n){
                a=min(a,costs[1]+dp[index]);
            }else{
                a=min(a,costs[1]);
            }
            index=lower_bound(days.begin(),days.end(),curr_day+30)-days.begin();
            if(index<n){
                a=min(a,costs[2]+dp[index]);
            }else{
                a=min(a,costs[2]);
            }
            dp[i]=a;
        }
        return dp[0];
    }
};