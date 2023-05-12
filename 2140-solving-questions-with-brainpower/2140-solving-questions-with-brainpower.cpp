class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long ans=0;
        int n=questions.size();
        long long dp[n];
        dp[n-1]=questions[n-1][0];
        for(int i=n-2;i>=0;i--){
                dp[i]=max(dp[i+1],questions[i][0]+((i+1+questions[i][1]<n)?dp[i+1+questions[i][1]]:0));
        }
        return dp[0];
    }
};