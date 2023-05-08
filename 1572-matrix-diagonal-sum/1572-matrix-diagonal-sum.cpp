class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        if(n%2==0){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=mat[i][i];
                sum+=mat[n-i-1][i];
            }
            return sum;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=mat[i][i];
            sum+=mat[n-i-1][i];
        }
        sum-=mat[n/2][n/2];
        return sum;
    }
};