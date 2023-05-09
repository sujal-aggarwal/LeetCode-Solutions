class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row_end=matrix.size()-1,col_end=matrix[0].size()-1,col_start=0,row_start=0;
        vector<int>ans;
        while(row_end>=row_start&&col_end>=col_start){
            for(int i=col_start;i<=col_end;i++){
                ans.push_back(matrix[row_start][i]);
            }
            row_start++;
            if(row_end>=row_start){
                for(int i=row_start;i<=row_end;i++){
                    ans.push_back(matrix[i][col_end]);
                }
                col_end--;
                if(col_end>=col_start){
                    for(int i=col_end;i>=col_start;i--){
                        ans.push_back(matrix[row_end][i]);
                    }
                    row_end--;
                    if(row_end>=row_start){
                        for(int i=row_end;i>=row_start;i--){
                            ans.push_back(matrix[i][col_start]);
                        }
                        col_start++;
                    }
                }
            }
        }
        return ans;
    }
};