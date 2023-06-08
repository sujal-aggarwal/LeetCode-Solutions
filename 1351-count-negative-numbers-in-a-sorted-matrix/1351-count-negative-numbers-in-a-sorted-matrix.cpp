class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt=0,m=grid.size(),n=grid[0].size();
        int i=0,j=n-1;
        while(i<m&&j>=0){
            cnt+=(n-1-j);
            while(j>=0&&grid[i][j]<0){
                j--;
                cnt++;
            }
            i++;
        }
        if(i!=m){
            cnt+=(n*(m-i));
        }
        return cnt;
    }
};