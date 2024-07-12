class Solution {
public:
    int n;
    bool kahn(unordered_map<int,vector<int>>& adj){
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
        
        int count=0;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto j:adj[node]){
                indegree[j]--;
                
                if(indegree[j]==0){
                    q.push(j);
                    count++;
                }
            }
        }
        
        return count==n;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n=numCourses;
        unordered_map<int,vector<int>>adj;
        for(auto vec:prerequisites){
            adj[vec[0]].push_back(vec[1]);
        }
        return kahn(adj);
    }
};