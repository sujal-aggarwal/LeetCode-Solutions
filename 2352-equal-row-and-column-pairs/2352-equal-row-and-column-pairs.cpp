class Solution {
public:
    string b(int n){
        string s="";
        while(n>0){
            s+=((n%2)+'0');
            n=n>>1;
        }
        return s;
    }
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<string,int>mp_row;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++){
                s+=b(grid[i][j]);
            }
            mp_row[s]++;
        }
        unordered_map<string,int>mp_col;
        for(int j=0;j<n;j++){
            string s="";
            for(int i=0;i<n;i++){
                s+=b(grid[i][j]);
            }
            mp_col[s]++;
        }
        int cnt=0;
        for(auto [i,j]:mp_row){
            if(mp_col.count(i)>0){
                cnt+=(mp_row[i]*mp_col[i]);
            }
        }
        return cnt;
    }
};