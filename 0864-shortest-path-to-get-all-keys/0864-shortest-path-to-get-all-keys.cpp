class Solution {
public:
    vector<vector<int>>dir={
                {-1,0},
        {0,-1},         {0,1},
                {1,0}
    };
    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        queue<vector<int>>q;
        
        int count=0;
        
        int x=0;
        int y=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>='a'&&grid[i][j]<='f'){
                    count++;
                }else if(grid[i][j]=='@'){
                    x=i;y=j;
                }
            }
        }
        
        int final_status=pow(2,count)-1;

        q.push({x,y,0,0});
        
        int visited[m][n][final_status+1];
        memset(visited,0,sizeof(visited));

        while(!q.empty()){
            
            auto temp=q.front();
            q.pop();
            
            int i=temp[0];
            int j=temp[1];
            int steps=temp[2];
            int curr_status=temp[3];

            if(curr_status==final_status)return steps;

            for(auto d:dir){
                int new_i=i+d[0];
                int new_j=j+d[1];

                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] != '#') {
                    char ch = grid[new_i][new_j];
                        
                    if(grid[new_i][new_j] >= 'A' && grid[new_i][new_j] <= 'F') { 
                        
                        if(visited[new_i][new_j][curr_status] == 0 && 
                          ((curr_status >> (ch-'A')) & 1) == 1) { 
                            visited[new_i][new_j][curr_status] = 1;
                            q.push({new_i, new_j, steps+1, curr_status});
                        }
                        
                    } else if(grid[new_i][new_j] >= 'a' && grid[new_i][new_j] <= 'f') { 
                        
                        int new_status = curr_status | (1 << (ch - 'a'));
                        
                        if(visited[new_i][new_j][new_status] == 0) {
                            visited[new_i][new_j][new_status] = 1;
                            q.push({new_i, new_j, steps+1, new_status});
                        }
                        
                    } else {
                        if(visited[new_i][new_j][curr_status] == 0) {
                            visited[new_i][new_j][curr_status] = 1;
                            q.push({new_i, new_j, steps+1, curr_status});
                        }
                    }
                    
                }
            }
        }
        return -1;
    }
};