class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int>index(names.size());
        iota(index.begin(),index.end(),0);
        sort(index.begin(),index.end(),[&](int& i,int& i2){
            return heights[i]>heights[i2];
        });
        vector<string>ans;
        for(int i=0;i<names.size();i++){
            ans.push_back(names[index[i]]);
        }
        return ans;
    }
};