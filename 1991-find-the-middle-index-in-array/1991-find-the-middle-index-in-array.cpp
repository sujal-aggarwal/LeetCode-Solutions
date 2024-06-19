class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        int rightSum=accumulate(nums.begin(),nums.end(),0)-nums[0];
        int leftSum=0;
        for(int i=0;i<n;i++){
            if(leftSum==rightSum)return i;
            leftSum+=nums[i];
            if(i+1<n){
                rightSum-=nums[i+1];
            }
        }
        return -1;
    }
};