class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>mp;
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0],b=edges[i][1];
            if(mp.find(a)!=mp.end())return a;
            if(mp.find(b)!=mp.end())return b;
            mp[a]++;
            mp[b]++;
        }
        return 0;
    }
};