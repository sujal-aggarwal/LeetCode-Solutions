class Solution {
public:
    int row;
    int col;
    vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
    bool dfs(vector<vector<int>>&grid,int i,int j){
        if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 1) {
            return false;
        }
        
        if(i == row-1)
            return true;
        
        grid[i][j] = 1;
        for(vector<int> &d : dir) {
            int new_i = i + d[0];
            int new_j = j + d[1];
            
            if(dfs(grid, new_i, new_j))
                return true;
        }
        
        
        return false;
    }
    bool cross(vector<vector<int>>&cells,int mid){
        vector<vector<int>> grid(row,vector<int>(col,0));
        for(int i=0;i<=mid;i++){
            int x=cells[i][0]-1;
            int y=cells[i][1]-1;
            grid[x][y]=1;
        }
        
        
        for(int i=0;i<col;i++){
            if(dfs(grid,0,i)){
                return true;
            }
        }
        
        return false;
    }
    int latestDayToCross(int rw, int c, vector<vector<int>>& cells) {
        row=rw;
        col=c;
        
        int l=-1,r=cells.size();
        while(r>l+1){
            int mid=l+(r-l)/2;
            if(cross(cells,mid)){
                l=mid;
            }else{
                r=mid;
            }
        }
        return (l==-1)?0:l+1;
    }
};