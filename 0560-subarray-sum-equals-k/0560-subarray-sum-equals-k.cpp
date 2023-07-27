class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix;
        prefix.push_back(nums[0]);
        for(int i=1;i<n;i++){
            prefix.push_back(prefix.back()+nums[i]);
        }
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(prefix[i]==k){
                ans++;
            }
            
            if(mp.find(prefix[i]-k)!=mp.end()){
                ans+=mp[prefix[i]-k];
            }
            
            mp[prefix[i]]++;
        }
        return ans;
    }
};