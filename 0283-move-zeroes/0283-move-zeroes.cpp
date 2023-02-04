class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        for(int cur=0;cur<nums.size();cur++)
        {
            if(nums[cur]!=0)
            {
                nums[i++]=nums[cur];
            }
        }
        for(;i<nums.size();i++)
            nums[i]=0;
    }
};