class Solution {
public:
    int findMaxScore(vector<vector<int>>& dp, vector<pair<int, int>>& arr, int prev, int index) {
        // Return 0 if we have iterated over all the players.
        if (index >= arr.size()) {
            return 0;
        }
        
        // We have already calculated the answer, so no need to go into recursion.
        if (dp[prev + 1][index] != -1) {
            return dp[prev + 1][index];
        }

        // If we can add this player, return the maximum of two choices we have.
        if (prev == -1 || arr[index].second >= arr[prev].second) {
            return dp[prev + 1][index] = max(findMaxScore(dp, arr, prev, index + 1), 
                       arr[index].second + findMaxScore(dp, arr, index, index + 1));
        }
        
        // This player cannot be added; return the corresponding score.
        return dp[prev + 1][index] = findMaxScore(dp, arr, prev, index + 1);
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < scores.size(); i++) {
            arr.push_back({ages[i], scores[i]});
        }
        
        // Sort in ascending order of age and then by score.
        sort(arr.begin(), arr.end());
        // Mark all the states as -1, denoting not yet calculated.
        vector<vector<int>> dp(scores.size(), vector<int>(scores.size(), -1));
        return findMaxScore(dp, arr, -1, 0);
    }
};