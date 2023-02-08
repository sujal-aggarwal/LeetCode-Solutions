class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int n=nums.size(),end=0,can_reach=0;
        for(int i=0;i<n-1;i++)
        {
            can_reach=max(can_reach,i+nums[i]);
            if(i==end)
            {
                jumps++;
                end=can_reach;
            }
        }
        return jumps;
    }
};