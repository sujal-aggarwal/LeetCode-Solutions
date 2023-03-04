class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int leftbound=-1,minPosition=-1,maxPosition=-1,n=nums.size();
        long long count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==minK){
                minPosition=i;
            }if(nums[i]==maxK){
                maxPosition=i;
            }if(nums[i]>maxK||nums[i]<minK){
                leftbound=i;
            }
            count+=max(0,min(minPosition,maxPosition)-leftbound);
        }
        return count;
    }
};