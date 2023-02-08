class Solution {
public:
    int Area(vector<vector<int>>& grid, int i, int j) {
        if(grid[i][j]!=1)
            return 0;
        int value=1;
        vector<vector<int>>ans=grid;
        grid[i][j]=0;
        int rows=grid.size(),columns=grid[i].size();
        if(j+1<columns&&ans[i][j+1]==1)
            value+=Area(grid,i,j+1);
        if(j-1>=0&&ans[i][j-1]==1)
            value+=Area(grid,i,j-1);
        if(i+1<rows&&ans[i+1][j]==1)
            value+=Area(grid,i+1,j);
        if(i-1>=0&&ans[i-1][j]==1)
            value+=Area(grid,i-1,j);
        return value;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                    maxarea=max(maxarea,Area(grid,i,j));
            }
        }
        return maxarea;
    }
};