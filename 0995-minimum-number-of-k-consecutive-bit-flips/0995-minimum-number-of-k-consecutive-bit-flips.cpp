class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>hasFlipped(n,0);
        int flipCount=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(i>=k && hasFlipped[i-k]==1){
                flipCount--;
            }
            if((nums[i]+flipCount%2)%2==0 && i<=n-k){
                ans++;
                flipCount++;
                hasFlipped[i]++;
                nums[i]=1;
            }else{
                nums[i]=(nums[i]+flipCount%2)%2;
                if(nums[i]==0)return -1;
            }
        }
        return ans;
    }
};