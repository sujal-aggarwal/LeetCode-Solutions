class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(string&s,int l,int r){
        if(l==r)return 1;
        if(l>r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int i=l;
        for(;i<=r;i++){
            if(s[i]!=s[l])break;
        }
        if(i==r+1)return 1;
        int no_partition=1+solve(s,i,r);
        int partition=INT_MAX;
        for(int j=i;j<=r;j++){
            if(s[j]==s[l]){
                partition=min(partition,solve(s,i,j-1)+solve(s,j,r));
            }
        }
        return dp[l][r]=min(partition,no_partition);
    }
    int strangePrinter(string s) {
        n=s.length();
        dp.resize(n,vector<int>(n,-1));
        return solve(s,0,n-1);
    }
};