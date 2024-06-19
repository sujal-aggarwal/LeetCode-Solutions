class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix;
        prefix.push_back(nums[0]);
        for(int i=1;i<n;i++){
            prefix.push_back(max(nums[i],prefix[i-1]));
        }
        vector<int>suffix(n,0);
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(nums[i],suffix[i+1]);
        }
        long long ans=0;
        for(int i=1;i<n-1;i++){
            long long curr= (prefix[i-1]-nums[i]*1L)*suffix[i+1];
            ans=max(ans,curr);
        }
        return ans;
    }
};