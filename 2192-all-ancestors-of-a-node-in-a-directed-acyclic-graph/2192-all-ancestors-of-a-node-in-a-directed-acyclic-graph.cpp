class Solution {
public:
    int n;
    unordered_map<int,vector<int>> graph;
    void dfs(vector<vector<int>>&ans, int parent, int source){
        for(auto i:graph[parent]){
            if(ans[i].empty() || ans[i].back()!= source){
                ans[i].push_back(source);
                dfs(ans,i,source);
            }
        }
        return ;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        this->n=n;
        for(auto vec:edges){
            int i=vec[0];
            int j=vec[1];
            graph[i].push_back(j);
        }
        vector ans(n,vector<int>());
        for(int i=0;i<n;i++){
            dfs(ans,i,i);
        }
        return ans;
    }
};