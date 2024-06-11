class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        for(int i:arr1){
            mp[i]++;
        }
        vector<int>ans;
        for(int i:arr2){
            for(int index=0;index<mp[i];index++){
                ans.push_back(i);
            }
            mp.erase(i);
        }
        for(auto [x,y]:mp){
            for(int index=0;index<y;index++){
                ans.push_back(x);
            }
        }
        return ans;
    }
};