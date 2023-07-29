class Solution {
public:
    vector<vector<int>>serve={{100,0},{75,25},{50,50},{25,75}};
    vector<vector<double>>dp;
    double Prob(int a,int b){
        if(a<=0&&b<=0)return 0.5;
        if(a<=0)return 1.0;
        if(b<=0)return 0;
        if(dp[a][b]!=-1.0)return dp[a][b];
        double ans=0;
        for(auto i:serve){
            int new_a=a-i[0];
            int new_b=b-i[1];
            ans+=Prob(new_a,new_b);
        }
        return dp[a][b]=0.25*ans;
    }
    double soupServings(int n) {
        if(n>=4000)return 1;
        dp.resize(n+1,vector<double>(n+1,-1.0));
        return Prob(n,n);
    }
};