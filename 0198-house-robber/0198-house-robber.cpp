class Solution {
public:
    int maxMoneyLooted(vector<int>&arr, int n)
    {
        if(n==0)
		return 0;
        if(n==1||n==2)
        {
            if(n-1==0)
                return arr[0];
            return max(arr[0],arr[1]);
        }
        int *dp=new int [n+1];
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        
        for(int i=2;i<n;i++)
        {
            int a=dp[i-2]+arr[i];
            int b=dp[i-1];
            dp[i]=max(a,b);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        return maxMoneyLooted(nums,nums.size());
    }
};