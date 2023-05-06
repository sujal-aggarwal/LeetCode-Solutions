class Solution {
public:
    int MOD=1000000007;
    int solve(int a,int b){
        int ans=1;
        while(b){
            if(b&1){ans=((ans%MOD)*1LL*(a%MOD))%MOD;}
            a=(a*1LL*a)%MOD;
            b=b>>1;
        }
        return ans;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int ans=0;
        while(i<=j){
            if(nums[i]+nums[j]>target){j--;continue;}
            ans=(ans%MOD+0LL+solve(2,j-i)%MOD)%MOD;
            i++;
        }
        return ans;
    }
};