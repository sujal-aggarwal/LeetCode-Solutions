class Solution {
public:
    int n;
    vector<int> dir = {1,0,-1,0,1};
    vector<vector<char>> adj;
    void dfs(int i, int j) {
        if (i < 0 || i >= n * 3 || j < 0 || j >= n * 3 || adj[i][j] != '0') {
            return;
        }
        adj[i][j] = '1';
        for (int idx = 0; idx < dir.size() - 1; ++idx) {
            int new_i = i + dir[idx];
            int new_j = j + dir[idx + 1];
            dfs(new_i, new_j);
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        n=grid.size();
        adj.resize(n * 3, vector<char>(n * 3, '0'));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '/') {
                    // Blocking cells for '/'
                    adj[i * 3 + 0][j * 3 + 2] = '1'; // Top-right
                    adj[i * 3 + 1][j * 3 + 1] = '1'; // Center
                    adj[i * 3 + 2][j * 3 + 0] = '1'; // Bottom-left
                } else if (grid[i][j] == '\\') {
                    // Blocking cells for '\'
                    adj[i * 3 + 0][j * 3 + 0] = '1'; // Top-left
                    adj[i * 3 + 1][j * 3 + 1] = '1'; // Center
                    adj[i * 3 + 2][j * 3 + 2] = '1'; // Bottom-right
                }
            }
        }
        
        int compartments=0;
        for (int i = 0; i < n * 3; ++i) {
            for (int j = 0; j < n * 3; ++j) {
                if (adj[i][j] == '0') {
                    dfs(i, j);
                    compartments++;
                }
            }
        }
        return compartments;
    }
};