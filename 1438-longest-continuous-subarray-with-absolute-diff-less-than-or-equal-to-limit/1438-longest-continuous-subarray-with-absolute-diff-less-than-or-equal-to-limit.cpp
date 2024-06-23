class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        multiset<int>s;
        int ans=0;
        int i=0,j=0;
        while(j<n){
            s.insert(nums[j]);
            int min_element=*s.begin();
            int max_element=*s.rbegin();
            if(max_element-min_element>limit){
                while(max_element-min_element>limit && i<j){
                    s.erase(s.find(nums[i++]));
                    min_element=*s.begin();
                    max_element=*s.rbegin();
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};