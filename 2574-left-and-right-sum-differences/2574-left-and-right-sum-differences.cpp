class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int leftSum=0;
        int rightSum=sum-nums[0];
        vector<int>arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back(abs(leftSum-rightSum));
            leftSum+=nums[i];
            if(i+1<nums.size())
                rightSum-=nums[i+1];
        }
        return arr;
    }
};