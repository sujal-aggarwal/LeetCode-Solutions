class Solution {
public:
    int m,n;
    bool check(vector<vector<char>>&board,int i,int j){
        if(i!=0&&board[i-1][j]=='X')return false;
        if(j!=0&&board[i][j-1]=='X')return false;
        return true;
    }
    int countBattleships(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    if(check(board,i,j)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};