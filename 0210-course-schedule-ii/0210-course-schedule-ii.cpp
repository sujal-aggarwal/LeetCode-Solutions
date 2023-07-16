class Solution {
public:
    vector<int> findOrder(int v, vector<vector<int>>& prerequisites) {
        vector graph(v,vector<int>());
        for(auto i:prerequisites){
            graph[i[1]].push_back(i[0]);
        }
        
        vector<int>indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto it:graph[i]){
                indegree[it]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0)q.push(i);
        }
        
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto i:graph[node]){
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
        }
        
        if(topo.size()==v)return topo;
        return {};
    }
};