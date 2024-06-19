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
            }
        }
        int totalFreq=mp[target];
        int currFreq=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]==target){
                currFreq++;
            }
            int rightFreq=totalFreq-currFreq;
            if(currFreq*2 > i+1 && rightFreq*2 > n-i-1)return i;
        }
        return -1;
    }
};