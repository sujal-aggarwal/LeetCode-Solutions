class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size();
        vector<vector<int>>ans;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[groupSizes[i]].push_back(i);
        }
        for(auto [i,j]:mp){
            int no_of_groups=j.size()/i;
            vector<int>group;
            for(auto element:j){
                group.push_back(element);
                if(group.size()==i){
                    ans.push_back(group);
                    group.clear();
                }
            }
        }
        return ans;
    }
};