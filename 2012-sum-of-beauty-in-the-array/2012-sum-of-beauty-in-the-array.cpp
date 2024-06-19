class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n,0);
        vector<int>suffix(prefix);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            prefix[i]=max(nums[i],prefix[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=min(suffix[i+1],nums[i]);
        }
        int sum=0;
        for(int i=1;i<n-1;i++){
            if(prefix[i-1]<nums[i] && nums[i]<suffix[i+1]){
                sum+=2;
            }else if(nums[i-1]<nums[i] && nums[i]<nums[i+1]){
                sum+=1;
            }
        }
        return sum;
    }
};