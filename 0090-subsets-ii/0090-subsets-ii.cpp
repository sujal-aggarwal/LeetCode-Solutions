class Solution {
public:
    int n;
    multiset<int> solve(vector<int>&nums,int bit){
        multiset<int>arr;
        for(int i=n-1;i>=0&&bit>0;i--){
            if(bit&1){
                arr.insert(nums[i]);
            }
            bit=bit>>1;
        }
        return arr;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        set<multiset<int>>s;
        vector<vector<int>>arr;
        for(int i=0;i<(1<<n);i++){
            s.insert(solve(nums,i));
        }
        for(auto i:s){
            vector<int>a;
            for(auto j:i){
                a.push_back(j);
            }
            arr.push_back(a);
        }
        return arr;
    }
};