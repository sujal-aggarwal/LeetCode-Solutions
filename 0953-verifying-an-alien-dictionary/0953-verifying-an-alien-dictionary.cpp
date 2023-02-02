class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n=words.size();
        int *dp=new int[n+1];
        for(int i=0;i<=n;i++)
            dp[i]=-1;
        if(n==1||n==0)
            return true;
        dp[n]=1;
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            bool ans=dp[i+1];
            if(!ans){
                dp[i]=0;
                continue;
            }
            for(int j=0;j<min(words[i].size(),words[i+1].size());j++)
            {
                int a=find(order.begin(),order.end(),words[i][j])-order.begin();
                int b=find(order.begin(),order.end(),words[i+1][j])-order.begin();
                if(a>b){
                    dp[i]=0;
                    break;
                }
                else if(a<b){
                    dp[i]=1;
                    break;
                }
            }
            if(dp[i]==-1)
            {
                if(words[i].size()>words[i+1].size()){
                    dp[i]=0;
                }
                else
                    dp[i]=1;
            }
        }
        return dp[0];
    }
};