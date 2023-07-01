class Solution {
public:
    int n;
    int dp(vector<int>&cookies,int k,vector<int>&sum,int index){
        if(index==n){
            return *max_element(sum.begin(),sum.end());
        }
        int diff=INT_MAX;
        for(int i=0;i<k;i++){
            sum[i]+=cookies[index];
            diff=min(diff,dp(cookies,k,sum,index+1));
            sum[i]-=cookies[index];
        }
        return diff;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        n=cookies.size();
        vector<int>sum(k,0);
        return dp(cookies,k,sum,0);
    }
};