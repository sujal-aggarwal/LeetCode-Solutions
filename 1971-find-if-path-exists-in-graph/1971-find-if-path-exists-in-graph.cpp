class dsu{
    public:
        vector<int>rank;
        vector<int>parent;

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
            }else if(rank[x_parent]>rank[y_parent]){
                parent[y_parent]=x_parent;
            }else{
                parent[x_parent]=y_parent;
                rank[y_parent]++;
            }
        }
    
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        dsu ex(n);
        for(int i=0;i<edges.size();i++){
            ex.unite(edges[i][0],edges[i][1]);
        }
        
        return (ex.find(source)==ex.find(destination));
    }
};