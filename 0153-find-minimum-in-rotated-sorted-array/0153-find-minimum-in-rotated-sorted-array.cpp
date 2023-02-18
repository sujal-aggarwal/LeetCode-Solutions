class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=-1,r=nums.size(),end=nums[nums.size()-1];
        while(r>l+1){
            int mid=(l+r)/2;
            if(nums[mid]<=end)
                r=mid;
            else
                l=mid;
        }
        return nums[r];
    }
};