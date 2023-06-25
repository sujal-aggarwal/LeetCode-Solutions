class Solution {
public:
    int dp[100][201];
    int mod=1e9+7;
    int ans(vector<int>&locations,int start,int finish,int fuel){
        if(fuel<0)return 0;
        int val=0;
        if(dp[start][fuel]!=-1)return dp[start][fuel];
        if(start==finish)val++;
        for(int i=0;i<locations.size();i++){
            if(i==start){continue;}
            int a=fuel-abs(locations[i]-locations[start]);
            if(a>=0)
                val=(val+ans(locations,i,finish,a))%mod;
        }
        return dp[start][fuel]=val;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp,-1,sizeof(dp));
        return ans(locations,start,finish,fuel);
    }
};