class Solution {
public:
    int n;
    vector<int> solve(vector<int>&nums,int bit){
        vector<int>arr;
        for(int i=n-1;i>=0&&bit>0;i--){
            if(bit&1){
                arr.push_back(nums[i]);
            }
            bit=bit>>1;
        }
        return arr;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>arr;
        for(int i=0;i<(1<<n);i++){
            arr.push_back(solve(nums,i));
        }
        return arr;
    }
};