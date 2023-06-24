class Solution {
public:
    int dp[20][10001];
    int ans(vector<int>&rods,int diff,int index){
        if(index>=rods.size()){
            return (diff==0)?0:INT_MIN;
        }
        if(dp[index][diff+5000]!=-1){
            return dp[index][diff+5000];
        }
        int curr=rods[index]+ans(rods,diff+rods[index],index+1);
        curr=max(curr,ans(rods,diff-rods[index],index+1));
        curr=max(curr,ans(rods,diff,index+1));
        return dp[index][diff+5000]=curr;
    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp,-1,sizeof(dp));
        return ans(rods,0,0);
    }
};