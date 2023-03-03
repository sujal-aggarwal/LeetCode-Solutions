class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n=nums.size();
        unordered_map<int,int>index;
        for(int i=0;i<n;i++){
            index[nums[i]]=i;
        }
        for(auto i:operations){
            int element=i[0];
            int new_element=i[1];
            int j=index[element];
            nums[j]=new_element;
            index.erase(element);
            index[new_element]=j;
        }
        return nums;
    }
};