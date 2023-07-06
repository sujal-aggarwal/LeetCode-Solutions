class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int length=INT_MAX;
        int sum=0;
        while(j<n){
            sum+=nums[j];
            if(sum>=target){
                length=min(length,j-i+1);
                while(sum>target&&i<j){
                    length=min(length,j-i+1);
                    sum-=nums[i];
                    i++;
                }
                if(sum==target){
                    length=min(length,j-i+1);
                }
            }
            j++;
        }
        j--;
        while(sum>target&&i<j){
            length=min(length,j-i+1);
            sum-=nums[i];
            i++;
        }
        if(sum==target){
            length=min(length,j-i+1);
        }
        return (length==INT_MAX)?0:length;
    }
};