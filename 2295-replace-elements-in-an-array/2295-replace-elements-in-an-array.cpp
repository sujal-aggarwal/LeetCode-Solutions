int m[1000001];
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]=i;
        }
        for(auto i:operations){
            int j=m[i[0]];
            nums[j]=i[1];
            m[i[1]]=j;
        }
        return nums;
    }
};