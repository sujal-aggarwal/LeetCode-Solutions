unordered_map<int,int>m;
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]=i;
        }
        for(auto i:operations){
            int element=i[0];
            int new_element=i[1];
            int j=m[element];
            nums[j]=new_element;
            m[new_element]=j;
        }
        return nums;
    }
};