class Solution {
public:
    vector<vector<vector<double>>>dp;
    vector<pair<int, int>> directions = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

    double helper( int N, int K , int row, int col ) {
        
        if ( row < 0 || row >= N || col < 0 || col >= N ) 
            return 0; 
        
        if (K==0)
            return 1;  
        
        if(dp[row][col][K]!=-1) 
            return dp[row][col][K];
        
        double ans = 0;
        for(auto &dir : directions) {
            int new_row = row + dir.first;
            int new_col = col + dir.second;
            ans += (double)helper(N, K-1, new_row, new_col);
        }
        
        return dp[row][col][K] = (double)(ans/8.0); 
    }
    
    
    double knightProbability(int n, int k, int row, int column) {
        dp.resize(n,vector(n,vector<double>(k+1,-1)));
        return helper( n , k , row , column); 
    }
};
