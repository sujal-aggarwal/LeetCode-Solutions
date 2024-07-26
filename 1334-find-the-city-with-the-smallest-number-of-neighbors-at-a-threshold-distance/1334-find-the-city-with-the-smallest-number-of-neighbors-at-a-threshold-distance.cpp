#define inf 1e9
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> grid(n,vector<int>(n,inf));
        for(int i=0;i<n;i++){
            grid[i][i]=0;
        }
        for(auto vec: edges){
            grid[vec[0]][vec[1]]=vec[2];
            grid[vec[1]][vec[0]]=vec[2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][k]!=inf && grid[k][j]!=inf){
                        grid[i][j]=min(grid[i][j], grid[i][k] + grid[k][j]);
                    }
                }
            }
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]<=distanceThreshold){
                    mp[i]++;
                }
            }
        }
        int city=0;
        int count=INT_MAX;
        for(auto [i,j]:mp){
            if(count>j){
                city=i;
                count=j;
            }else if(count==j){
                city=max(city,i);
            }
        }
        return city;
    }
};