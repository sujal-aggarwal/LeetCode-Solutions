class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector visited(n,vector<bool>(n,0));
        for(auto vec:dig){
            visited[vec[0]][vec[1]]=1;
        }
        int count=0;
        for(auto vec:artifacts){
            int rc1=vec[0];
            int c1=vec[1];
            int rc2=vec[2];
            int c2=vec[3];
            bool flag=true;
            for(int i=rc1;i<=rc2;i++){
                for(int y=c1;y<=c2;y++){
                    if(!visited[i][y]){
                        flag=false;
                    }
                }
            }
            count += (flag)?1:0;
        }
        return count;
    }
};