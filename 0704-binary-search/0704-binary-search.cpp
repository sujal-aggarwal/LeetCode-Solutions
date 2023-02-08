class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=-1,r=nums.size();
        while(r>l+1)
        {
            int m=(r+l)/2;
            if(nums[m]<target)
                l=m;
            else
                r=m;
        }
        if(r!=nums.size()&&nums[r]==target)
            return r;
        return -1;
    }
};