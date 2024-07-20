class Solution {
public:
    vector<vector<int>> ans;
    int m,n;
    void solve(vector<int>& rowSum,vector<int>& colSum){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int min_val=min(rowSum[i],colSum[j]);
                ans[i][j]+=min_val;
                rowSum[i]-=min_val;
                colSum[j]-=min_val;
            }
        }
    }
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        m=rowSum.size();
        n=colSum.size();
        ans.resize(m,vector<int>(n,0));
        solve(rowSum,colSum);
        return ans;
    }
};