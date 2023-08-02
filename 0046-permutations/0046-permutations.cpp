class Solution {
public:
    int n;
    vector<vector<int>>ans;
    void solve(vector<int>&nums,int ind){
        if(ind==n-1){
            ans.push_back(nums);
        }
        for(int i=ind;i<n;i++){
            swap(nums[ind],nums[i]);
            solve(nums,ind+1);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        solve(nums,0);
        return ans;
    }
};