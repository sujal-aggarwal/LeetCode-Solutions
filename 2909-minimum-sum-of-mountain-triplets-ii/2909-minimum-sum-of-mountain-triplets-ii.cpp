class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            prefix[i]=min(prefix[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=min(suffix[i+1],nums[i]);
        }
        int ans=-1;
        for(int i=1;i<n-1;i++){
            if(prefix[i-1]<nums[i] && suffix[i+1]<nums[i]){
                if(ans==-1){
                    ans=nums[i]+prefix[i-1]+suffix[i+1];
                }else{
                    ans=min(ans,nums[i]+prefix[i-1]+suffix[i+1]);
                }
            }
        }
        return ans;
    }
};