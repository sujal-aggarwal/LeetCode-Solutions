class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>arr;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0){
                arr.push_back(nums[i]);
                continue;
            }
            arr.push_back(arr.back()+nums[i]);
        }
        return arr;
    }
};