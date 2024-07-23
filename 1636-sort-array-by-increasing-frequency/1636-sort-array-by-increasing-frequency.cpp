class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        sort(nums.begin(),nums.end(),[&](int& i,int& i2){
            if(mp[i]==mp[i2])return i>i2;
            return mp[i]<mp[i2];
        });
        return nums;
    }
};