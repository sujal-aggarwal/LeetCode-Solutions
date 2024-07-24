class dsu {
public:
    vector<int> parent;
    vector<int> rank;

    dsu(int n) : rank(n, 0), parent(n, 0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        return parent[x] = (parent[x] == x) ? x : find(parent[x]);
    }

    void unite(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) return;
        if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
};
class Solution {
public:
    int n;
    vector<int> Cycle(vector<vector<int>>& edges,vector<int> blacklist){
        dsu ex(n+1);
        
        for(auto vec:edges){
            if(vec==blacklist)continue;
            if(ex.find(vec[0])==ex.find(vec[1]))return {vec[0],vec[1]};
            ex.unite(vec[0],vec[1]);
        }
        
        return {};
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        n=edges.size();
        vector<int>indegree(n+1,0);
        for(int i=0;i<n;i++){
            if(indegree[edges[i][1]]){
                vector<int>prev={indegree[edges[i][1]],edges[i][1]};
                vector<int>curr=edges[i];
                vector<int> res1=Cycle(edges,prev);
                vector<int> res2=Cycle(edges,curr);
                if(res1.size()>0 && res2.size()>0)return curr;
                if(res2.size()>0)return prev;
                return curr;
            }else{
                indegree[edges[i][1]]=edges[i][0];
            }
        }
        return Cycle(edges,{});
        
    }
};