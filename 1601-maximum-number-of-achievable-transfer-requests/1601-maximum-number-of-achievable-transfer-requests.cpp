class Solution {
public:
    vector<pair<int,int>>arr;
    int ans(vector<vector<int>>&requests,int index,int mask,vector<vector<int>>&dp){
        if(index==requests.size()){
            for(auto j:arr){
                if(j.first!=j.second)return 0;
            }
            return __builtin_popcount(mask);
        }
        if(dp[index][mask]!=-1)return dp[index][mask];
        auto temp=requests[index];
        int f=temp[0];
        int s=temp[1];
        
        arr[f].second++;
        arr[s].first++;
        int a=ans(requests,index+1,mask|(1<<index),dp);
        arr[f].second--;
        arr[s].first--;
        
        int b=ans(requests,index+1,mask,dp);
        
        return dp[index][mask]=max(a,b);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m=requests.size();
        arr.resize(n,{0,0});
        vector dp(m,(vector<int>(1<<m,-1)));
        return ans(requests,0,0,dp);
    }
};