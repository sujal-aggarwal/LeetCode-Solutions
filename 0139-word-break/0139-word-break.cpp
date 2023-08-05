class Solution {
public:
    unordered_map<string,int>mp;
    vector<int>dp;
    int n;
    bool solve(int ind,string s){
        if(ind>=n){
            return true;
        }
        if(dp[ind]!=-1)return dp[ind];
        string s1="";
        bool ans=false;
        for(int i=ind;i<n;i++){
            s1+=s[i];
            if(mp.count(s1)){
                ans=max(ans,solve(i+1,s));
            }
        }
        return dp[ind]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        for(auto i:wordDict){
            mp[i]++;
        }
        dp.resize(n,-1);
        return solve(0,s);
    }
};