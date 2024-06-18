class Solution {
    int dp[1001][26][26];
    int solve(vector<string>& words, int i, char last, char first) {
        if(i == size(words))return 0;
        
        if(dp[i][last - 'a'][first - 'a'] != -1) return dp[i][last - 'a'][first - 'a'];
        
        int ch1 = 0, ch2 = 0,n = words[i].size();
        
        ch1 = (last == words[i][0] ? 1 : 0) + solve(words, i+1, words[i][n-1], first);
        
        ch2 = (first == words[i][n-1] ? 1 : 0) + solve(words,i+1,last,words[i][0]);
        
        return dp[i][last - 'a'][first - 'a'] = max(ch1, ch2);
    }
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        
        if(words.size() == 1)return words[0].size();
        memset(dp, -1, sizeof dp);
        
        int totSize = 0;
        for(auto &x: words)totSize += x.size();
        
        return totSize - solve(words,1,words[0][words[0].size() - 1], words[0][0]);
    }
};