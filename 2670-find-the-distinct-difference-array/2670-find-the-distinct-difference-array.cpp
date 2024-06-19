class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n,0);
        vector<int>suffix(prefix);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            prefix[i]=mp.size();
        }
        mp.clear();
        for(int i=n-1;i>=0;i--){
            mp[nums[i]]++;
            suffix[i]=mp.size();
        }
        vector<int>diff;
        for(int i=0;i<n;i++){
            if(i==n-1){
                diff.push_back(prefix[i]);
                continue;
            }
            diff.push_back(prefix[i]-suffix[i+1]);
        }
        return diff;
    }
};