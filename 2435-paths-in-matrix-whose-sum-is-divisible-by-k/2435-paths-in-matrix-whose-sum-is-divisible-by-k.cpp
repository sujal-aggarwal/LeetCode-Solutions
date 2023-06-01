class Solution {
public:
    #define MOD 1000000007
    int m,n;
    int ans(vector<vector<int>>&grid,vector<vector<vector<int>>>&dp,int k,int i,int j ,int sum){
        if(i>m||j>n){return 0;}
        if(i==m&&j==n){
            sum+=grid[i][j];
            if(sum%k==0){return 1;}
            return 0;
        }
        if(dp[i][j][sum]!=-1){
            return dp[i][j][sum];
        }
        return dp[i][j][sum%k]=(ans(grid,dp,k,i+1,j,(sum+grid[i][j])%k)+ans(grid,dp,k,i,j+1,(sum+grid[i][j])%k))%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m=grid.size()-1;
        n=grid[0].size()-1;
        vector dp(m+1,vector(n+1,vector<int>(k+1,-1)));
        return ans(grid,dp,k,0,0,0);
    }
};