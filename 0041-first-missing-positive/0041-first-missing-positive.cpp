class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
            This question uses a new approach 
            i.e. Negative Marking
        */
        for(int j=0;j<nums.size();j++){
            while(nums[j]>0&&nums[j]<=nums.size()&&nums[nums[j]-1]!=nums[j]){
                swap(nums[nums[j]-1],nums[j]);
            }
        }
        for(auto i:nums){
            cout<<i<<" ";
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};