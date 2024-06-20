class Solution {
public:
    int n;
    bool isPossible(vector<int>&nums,int threshold, int curr){
        int count=0;
        for(int i=0;i<n;i++){
            count+=((nums[i]+curr-1)/curr);
        }
        return count<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        n=nums.size();
        int minThreshold=1;
        int maxThreshold=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(minThreshold<=maxThreshold){
            int midThreshold=minThreshold + (maxThreshold-minThreshold)/2;
            if(isPossible(nums,threshold,midThreshold)){
                ans=midThreshold;
                maxThreshold=midThreshold-1;
            }
            else{
                minThreshold=midThreshold+1;
            }
        }
        return ans;
    }
};