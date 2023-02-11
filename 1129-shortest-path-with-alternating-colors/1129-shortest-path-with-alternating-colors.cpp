class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red,
                                         vector<vector<int>>& blue) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& a : red) {
            adj[a[0]].push_back({a[1], 0});
        }
        for (auto& b : blue) {
            adj[b[0]].push_back({b[1], 1});
        }

        vector<int> answer(n, -1);
        vector<vector<bool>> visit(n, vector<bool>(2));
        queue<vector<int>> q;
        q.push({0, 0, -1});
        visit[0][1] = visit[0][0] = true;
        answer[0] = 0;

        while (!q.empty()) {
            auto front = q.front();
            int node = front[0], steps = front[1], prevColor = front[2];
            q.pop();

            for (auto& [neighbor, color] : adj[node]) {
                if (!visit[neighbor][color] && color != prevColor) {
                    visit[neighbor][color] = true;
                    q.push({neighbor, 1 + steps, color});
                    if (answer[neighbor] == -1) answer[neighbor] = 1 + steps;
                }
            }
        }
        return answer;
    }
};