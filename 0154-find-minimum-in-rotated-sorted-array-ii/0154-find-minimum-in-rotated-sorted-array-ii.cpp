class Solution {
public:
    bool sorted(vector<int>&nums,int&i){
        for(;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1])
                return false;
        }
        return true;
    }
    int findMin(vector<int>& nums) {
        int i=0;
        if(sorted(nums,i))
            return nums[0];
        return nums[i+1];
    }
};