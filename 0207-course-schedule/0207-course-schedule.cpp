class Solution {
public:
    int n;
    bool dfs(unordered_map<int,vector<int>>& adj,vector<int>& visited,vector<int>& inRecursion, int u){
        visited[u]=1;
        inRecursion[u]=1;
        for(auto v:adj[u]){
            if(visited[v] && inRecursion[v])return true;
            if(!visited[v] && dfs(adj,visited,inRecursion,v))return true;
        }
        inRecursion[u]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n=numCourses;
        unordered_map<int,vector<int>>adj;
        for(auto vec:prerequisites){
            adj[vec[0]].push_back(vec[1]);
        }
        
        vector<int>visited(n,0);
        vector<int>inRecursion(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i] && dfs(adj,visited,inRecursion,i)){
                return false;
            }
        }
        return true;
    }
};