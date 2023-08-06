class Solution {
public:
    typedef long long ll;
    ll N,GOAL,K;
    ll mod=1e9+7;
    int dp[101][101];
    ll solve(int count,int unique){
        if(count==GOAL){
            if(unique==N)return 1;
            return 0;
        }
        if(dp[count][unique]!=-1)return dp[count][unique];
        ll result=0;
        if(unique<N)
            result+=(N-unique)*solve(count+1,unique+1);
        if(unique>K)
            result+=(unique-K)*solve(count+1,unique);
        return dp[count][unique]=result%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        N=n;
        GOAL=goal;
        K=k;
        memset(dp,-1,sizeof(dp));
        return solve(0,0);
    }
};