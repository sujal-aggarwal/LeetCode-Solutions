class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=-1,r=nums.size();
        while(r>l+1)
        {
            int m=l+(r-l)/2;
            if(nums[m]<=target)
                l=m;
            else
                r=m;
        }
        if(l==-1)
            return 0;
        if(nums[l]==target)
            return l;
        return l+1;
    }
};