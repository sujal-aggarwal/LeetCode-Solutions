class Solution {
public:
    int longestPalindromeSubseq(string &s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        for(int i=n;i>=0;i--)
        {
            for(int j=0;j<i;j++)
            {
                dp[i][j]=0;
            }
        }
        dp[n][n]=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<=n;j++)
            {
                if(i==j)
                    dp[i][j]=1;
                else if(s[i]==s[j])
                {
                    dp[i][j]=2+dp[i+1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n];
    }
};