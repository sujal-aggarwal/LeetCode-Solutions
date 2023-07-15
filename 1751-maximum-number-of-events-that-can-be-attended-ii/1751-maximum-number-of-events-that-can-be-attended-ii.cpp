class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int ans(vector<vector<int>>&events, int ind,int k){
        if(ind==n||k==0)return 0;
        if(dp[ind][k]!=-1)return dp[ind][k];
        int a=ans(events,ind+1,k);
        vector<int>temp={events[ind][1]+1,INT_MIN,INT_MIN};
        int next_ind=lower_bound(events.begin()+ind+1,events.end(),temp)-events.begin();
        int b=ans(events,next_ind,k-1)+events[ind][2];
        return dp[ind][k]=max(a,b);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        n=events.size();
        sort(events.begin(),events.end());
        dp.resize(n+1,vector<int>(k+1,-1));
        return ans(events,0,k);
    }
};