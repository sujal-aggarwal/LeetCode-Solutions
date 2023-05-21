class Solution {
public:
void dfs(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&visited,int rsize,int cosize,vector<int>&ri,vector<int>&ci){
    visited[r][c] = 1;

        for(int i=0;i<4;i++){
           int row = r + ri[i];
           int  col = c + ci[i];
            if(row >=0 && row<rsize && col>=0 && col<cosize && visited[row][col] == -1 && grid[row][col] == 1){
             
              dfs(row,col,grid,visited,rsize,cosize,ri,ci);
            }
     
}
}
int bfs2(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&visited,int rsize,int cosize,vector<int>&ri,vector<int>&ci,int identify){
    
    queue<pair<int,pair<int,int>>>qu;
    qu.push({r,{c,0}});
    while(!qu.empty()){
        int rows = qu.front().first,cols = qu.front().second.first,fliptime = qu.front().second.second;
        qu.pop();
        for(int i=0;i<4;i++){
           int row = rows + ri[i];
           int  col = cols + ci[i];
            if(row >=0 && row<rsize && col>=0 && col<cosize && visited[row][col] != identify && grid[row][col] == 0){
                visited[row][col] = identify;
                qu.push({row,{col,fliptime+1}});
            }else if(row >=0 && row<rsize && col>=0 && col<cosize && visited[row][col] == -1 && grid[row][col] == 1) return fliptime;
        }
    }
    return INT_MAX;
}
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,-1));
        vector<int>ri{+1,-1,0,0};
        vector<int>ci{0,0,-1,+1};
        for(int i=0;i<m;i++){
            int f = 0;
            for(int z=0;z<n;z++){
                if(grid[i][z]) {
                    visited[i][z] = 1;
                dfs(i,z,grid,visited,m,n,ri,ci);
                f=1;
                break;
                }
            }
            if(f==1) break;
        }
        int mins = INT_MAX;
        int start = 3;
        for(int i=0;i<m;i++){
            for(int z=0;z<n;z++){
                if(visited[z][i] == 1){
                    visited[z][i] = 2;
                   int ans =  bfs2(z,i,grid,visited,m,n,ri,ci,start++);
                   mins = min(ans,mins);
                }
                
            }
            if(mins == 1) break;
        }
        return mins;
    }
};