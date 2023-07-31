class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int ascii(string&s1,string&s2,int i,int j){
        if(i>=n&&j>=m)return 0;
        if(i>=n){
            int res=0;
            for(;j<m;j++)res+=s2[j];
            return res;
        }
        if(j>=m){
            int res=0;
            for(;i<n;i++)res+=s1[i];
            return res;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=ascii(s1,s2,i+1,j+1);
        }
        int a=s1[i]+ascii(s1,s2,i+1,j);
        int b=s2[j]+ascii(s1,s2,i,j+1);
        return dp[i][j]=min(a,b);
    }
    int minimumDeleteSum(string s1, string s2) {
        n=s1.size();
        m=s2.size();
        dp.resize(n,vector<int>(m,-1));
        return ascii(s1,s2,0,0);
    }
};