class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector ans(n,vector<int>(n));
        int row_end=n-1,col_end=n-1,col_start=0,row_start=0;
        int cnt=1;
        while(row_end>=row_start&&col_end>=col_start){
            for(int i=col_start;i<=col_end;i++){
                ans[row_start][i]=cnt++;
            }
            row_start++;
            for(int i=row_start;i<=row_end&&row_end>=row_start;i++){
                ans[i][col_end]=cnt++;
            }
            col_end--;
            for(int i=col_end;i>=col_start&&col_end>=col_start;i--){
                ans[row_end][i]=cnt++;
            }
            row_end--;
            for(int i=row_end;i>=row_start&&row_end>=row_start;i--){
                ans[i][col_start]=cnt++;
            }
            col_start++;
        }
        return ans;
    }
};