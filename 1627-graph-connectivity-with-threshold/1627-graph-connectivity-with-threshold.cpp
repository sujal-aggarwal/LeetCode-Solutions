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
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        dsu ex(n+1);
        int multiplier=(threshold+1);
        for(;multiplier<=n;multiplier++){
            int prev=multiplier;
            for(int val=2;multiplier*val <= n;val++){
                ex.unite(prev,multiplier*val);
                prev=multiplier*val;
            }
        }
        vector<bool>ans;
        for(auto vec:queries){
            int parent1=ex.find(vec[0]);
            int parent2=ex.find(vec[1]);
            if(parent1==parent2){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};