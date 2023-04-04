class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int>mp;
        int count=1;
        for(auto i:s){
            if(mp[i]>0){
                mp.clear();
                count++;
                mp[i]++;
                continue;
            }
            mp[i]++;
        }
        return count;
    }
};