class dsu{
public:
    vector<int>parent;
    vector<int>rank;
    
    dsu():rank(26,0),parent(26,0){
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
    }
    
    int find(int x){
        return parent[x]= (parent[x]==x)?x:find(parent[x]);
    }
    
    void unite(int x,int y){
        int xparent=find(x);
        int yparent=find(y);
        
        if(xparent==yparent)return;
        
        if(rank[xparent]>rank[yparent]){
            parent[yparent]=xparent;
        }else if(rank[xparent]<rank[yparent]){
            parent[xparent]=yparent;
        }else{
            parent[xparent]=yparent;
            rank[yparent]++;
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        sort(equations.begin(),equations.end(),[](string& s1,string& s2){
            return s1[1]>s2[1];
        });
        dsu ex;
        for(auto eq:equations){
            if(eq[1]=='!'){
                int parent1=ex.find(eq[0]-'a');
                int parent2=ex.find(eq[3]-'a');
                if(parent1==parent2)return false;
            }else{
                ex.unite(eq[0]-'a',eq[3]-'a');
            }
        }
        return true;
    }
};