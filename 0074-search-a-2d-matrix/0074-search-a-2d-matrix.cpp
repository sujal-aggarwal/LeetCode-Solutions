class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int left=-1;
        int right=m*n;
        while(right>left+1){
            int mid=left+(right-left)/2;
            int row=mid/n;
            int col=mid%n;
            if(matrix[row][col]==target){
                return true;
            }else if(matrix[row][col]>target){
                right=mid;
            }else{
                left=mid;
            }
        }
        return false;
    }
};