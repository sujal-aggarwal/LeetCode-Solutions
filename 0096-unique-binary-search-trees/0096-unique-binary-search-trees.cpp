class Solution {
public:
    vector<vector<int>>dp;
    int solve(int start,int end){
        if(start>=end){
            return 1;
        }
        string key=to_string(start)+" "+to_string(end);
        if(dp[start][end]!=-1)
            return dp[start][end];
        int ans=0;
        for(int i=start;i<=end;i++){
            int leftBst=solve(start,i-1);
            int rightBst=solve(i+1,end);
            ans+=(leftBst*rightBst);
        }
        return dp[start][end]=ans;
    }
    int numTrees(int n) {
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(1,n);
    }
};