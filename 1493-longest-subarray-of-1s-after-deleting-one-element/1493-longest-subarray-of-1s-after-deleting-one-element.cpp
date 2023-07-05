class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int count=0;
        int ans=0;
        while(j<n){
            if(nums[j]==0){
                count++;
            }
            if(count>1){
                while(count>1){
                    if(nums[i]==0){
                        count--;
                    }
                    i++;
                }
            }
            ans=max(ans,j-i);
            j++;
        }
        return ans;
    }
};