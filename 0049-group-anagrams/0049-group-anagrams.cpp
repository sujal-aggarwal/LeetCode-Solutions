class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto i:strs){
            string s="";
            unordered_map<char,int>m;
            for(auto j:i){
                m[j]++;
            }
            for(char j='a';j<='z';j++){
                s+=to_string(m[j]);
                s+=" ";
            }
            mp[s].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto [i,j]:mp){
            ans.push_back(j);
        }
        return ans;
    }
};