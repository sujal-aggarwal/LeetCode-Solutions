class Solution {
public:
    int INF=1e9+7;
    int jump(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        int n=nums.size();
        int *dp=new int[n];
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            dp[i]=INF;
            for(int j=1;j<=nums[i]&&i+j<nums.size();j++)
            {
                dp[i]=min(dp[i],dp[i+j]);
            }
            dp[i]++;
        }
        return dp[0];
    }
};