class Solution {
public:
    #define inf 1e9
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost){
        vector grid(26,vector<int>(26,inf));
        for(int i=0;i<26;i++){
            grid[i][i]=0;
        }
        for(int i=0;i<original.size();i++){
            int u=original[i]-'a';
            int v=changed[i]-'a';
            int wt=cost[i];
            grid[u][v]=min(grid[u][v],wt);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(grid[i][k]!=inf && grid[k][j]!=inf){
                        grid[i][j]=min(grid[i][j],grid[i][k]+grid[k][j]);
                    }
                }
            }
        }
        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(source[i]!=target[i]){
                int cost=grid[source[i]-'a'][target[i]-'a'];
                if(cost!=inf){
                    ans+=cost;
                }else{
                    return -1;
                }
            }
        }
        return ans;
    }
};