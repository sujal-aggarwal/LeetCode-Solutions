class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        int target=-1;
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]++;
            if(mp[i]>=((n/2)+1)){
                target=i;
                break;
            }
        }
        vector<int>suffix(n,0);
        suffix[n-1]=(nums[n-1]==target)?1:0;
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+((nums[i]==target)?1:0);
        }
        int currFreq=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]==target){
                currFreq++;
            }
            if(currFreq*2 > i+1 && suffix[i+1] * 2 > n-i-1  )return i;
        }
        return -1;
    }
};