class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>arr;
        int i=0;
        int j=n;
        while(j<2*n)
        {
            arr.push_back(nums[i]);
            arr.push_back(nums[j]);
            i++;
            j++;
        }
        return arr;
    }
};