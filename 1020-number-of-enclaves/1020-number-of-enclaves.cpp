class Solution {
public:
    int m,n;
    void dfs(vector<vector<int>>&grid,vector<vector<int>>&visited,int i,int j){
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==0||visited[i][j]==1){
            return ;
        }
        visited[i][j]=1;
        dfs(grid,visited,i+1,j);
        dfs(grid,visited,i-1,j);
        dfs(grid,visited,i,j+1);
        dfs(grid,visited,i,j-1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n));
        for(int i=0;i<n;i++){
            if(grid[0][i]==1&&visited[0][i]==0){
                dfs(grid,visited,0,i);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[m-1][i]==1&&visited[m-1][i]==0){
                dfs(grid,visited,m-1,i);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[i][0]==1&&visited[i][0]==0){
                dfs(grid,visited,i,0);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[i][n-1]==1&&visited[i][n-1]==0){
                dfs(grid,visited,i,n-1);
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&visited[i][j]==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};