class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int length=INT_MAX;
        int sum=0;
        while(j<n){
            sum+=nums[j];
            while(sum>=target&&i<=j){
                length=min(length,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return (length==INT_MAX)?0:length;
    }
};