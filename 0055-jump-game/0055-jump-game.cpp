class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int end=0;
        int far=0;
        for(int i=0;i<=far&&i<=n-1;i++)
        {
            far=max(far,i+nums[i]);
        }
        if(far>=n-1)
            return true;
        return false;
    }
};