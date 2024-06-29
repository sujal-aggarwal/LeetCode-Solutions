class Solution {
public:
    int n;
    unordered_map<int,vector<int>> adj;
    void topoSort(vector<int>& ans){
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto i:adj[node]){
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        this->n=n;
        for(auto vec:edges){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
        }
        vector<int>topologicalArray;
        topoSort(topologicalArray);
        vector ancestors(n,unordered_set<int>());
        
        for(auto i:topologicalArray){
            for(auto j:adj[i]){
                ancestors[j].insert(i);
                ancestors[j].insert(ancestors[i].begin(),ancestors[i].end());
            }
        }
        
        vector ans(n,vector<int>());
        
        for(int i=0;i<n;i++){
            ans[i] = vector<int>(ancestors[i].begin(),ancestors[i].end());
            sort(ans[i].begin(),ans[i].end());
        }
        
        return ans;
    }
};