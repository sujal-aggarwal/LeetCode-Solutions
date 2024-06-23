class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        multiset<int>s;
        int ans=0;
        int i=0,j=0;
        while(j<n){
            s.insert(nums[j]);
            while(*s.rbegin()-*s.begin()>limit && i<j){
                s.erase(s.find(nums[i++]));
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};