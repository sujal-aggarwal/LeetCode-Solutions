class Solution {
public:
    int n;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        unordered_map<string,int>appeared;
        for(int i=0;i<(1<<n);i++){
            vector<int>arr;
            string hashcode;
            for(int j=0;j<n;j++){
                int bit=(i>>j)&1;
                if(bit){
                    arr.push_back(nums[j]);
                    hashcode+=(to_string(nums[j])+" ");
                }
            }
            if(!appeared.count(hashcode)){
                ans.push_back(arr);
                appeared[hashcode]++;
            }
        }
        return ans;
    }
};