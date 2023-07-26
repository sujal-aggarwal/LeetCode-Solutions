class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<int> ans ={0,0};
        vector dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            if(i!=n-1){
                dp[i][i+1]=(s[i]==s[i+1]?true:false);
                if(s[i]==s[i+1]){
                    ans[0]=i;
                    ans[1]=i+1;
                }
            }
        }
        for(int diff=2;diff<n;diff++){
            for(int i=0;i<n-diff;i++){
                int j=i+diff;
                if(s[i]==s[j]&&dp[i+1][j-1]){
                    dp[i][j]=true;
                    ans[0]=i;
                    ans[1]=j;
                }
            }
        }
        return s.substr(ans[0],ans[1]-ans[0]+1);
    }
};