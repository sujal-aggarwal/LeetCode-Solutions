class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)
            return vector<int>()={-1,-1};
        int left=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int right=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(left==nums.size()||nums[left]!=target)
            return vector<int>()={-1,-1};
        return vector<int>()={left,right-1};
    }
};