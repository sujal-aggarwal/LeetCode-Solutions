class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int arr[grid.size()][grid[0].size()];
        int sum=0;
        for(int i=grid[0].size()-1;i>=0;i--){
            sum+=grid[grid.size()-1][i];
            arr[grid.size()-1][i]=sum;
        }
        sum=grid[grid.size()-1][grid[0].size()-1];
        for(int i=grid.size()-2;i>=0;i--){
            sum+=grid[i][grid[0].size()-1];
            arr[i][grid[0].size()-1]=sum;
        }
        for(int i=grid.size()-2;i>=0;i--){
            for(int j=grid[0].size()-2;j>=0;j--){
                arr[i][j]=grid[i][j]+min(arr[i+1][j],arr[i][j+1]);
            }
        }
        return arr[0][0];
    }
};