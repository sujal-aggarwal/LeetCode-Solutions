class dsu{
public:
    vector<int>parent;
    vector<int>rank;
    
    dsu(int n):rank(n,0),parent(n,0){
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    
    int find(int x){
        return parent[x] = (parent[x]==x)?x:find(parent[x]);
    }
    
    void unite(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        
        if(x_parent==y_parent)return;
        
        if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }else if(rank[y_parent]<rank[x_parent]){
            parent[y_parent]=x_parent;
        }else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        dsu ex(edges.size()+1);
        vector<int>ans(2,0);
        for(auto vec:edges){
            int u=vec[0];
            int v=vec[1];
            if(ex.find(u)!=ex.find(v)){
                ex.unite(u,v);
            }else{
                ans[0]=u;
                ans[1]=v;
            }
        }
        return ans;
    }
};