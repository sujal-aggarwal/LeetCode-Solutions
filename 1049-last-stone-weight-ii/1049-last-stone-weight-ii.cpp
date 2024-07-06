class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total_sum=accumulate(stones.begin(),stones.end(),0);
        int sum=total_sum/2;
        vector<int>dp(sum+1,0);
        dp[0]=1;
        int max_sum=0;
        for(int i:stones){
            vector<int>temp(dp);
            for(int j=i;j<=sum;j++){
                if(dp[j-i]){
                    temp[j]=1;
                    max_sum=max(max_sum,j);
                }
            }
            dp=temp;
        }
        return total_sum - 2*max_sum;
    }
};