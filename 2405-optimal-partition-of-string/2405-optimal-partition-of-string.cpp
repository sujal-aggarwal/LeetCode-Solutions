class Solution {
public:
    int partitionString(string s) {
        vector<int>v(26,0);
        int count=1;
        for(auto i:s){
            if(v[i-'a']>0){
                v.clear();
                count++;
                v.resize(26,0);
                v[i-'a']++;
                continue;
            }
            v[i-'a']++;
        }
        return count;
    }
};