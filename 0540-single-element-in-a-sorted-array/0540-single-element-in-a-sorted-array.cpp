class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int a=0;
        for(auto i:nums){
            a^=i;
        }
        return a;
    }
};