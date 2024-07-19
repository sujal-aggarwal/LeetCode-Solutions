class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>result;
        vector<int>min_row(m,0);
        for(int i=0;i<m;i++){
            int ans=INT_MAX;
            for(int j=0;j<n;j++){
                ans=min(ans,matrix[i][j]);
            }
            min_row[i]=ans;
        }
        for(int i=0;i<n;i++){
            int ans=INT_MIN;
            int row;
            for(int j=0;j<m;j++){
                if(matrix[j][i]>ans){
                    ans=matrix[j][i];
                    row=j;
                }
            }
            if(min_row[row]==ans){
                result.push_back(ans);
            }
        }
        return result;
    }
};