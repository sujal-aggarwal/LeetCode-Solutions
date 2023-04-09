class Solution {
public:
    int decode(string& s, int idx, int n, int * dp) {
        if (idx < n && s[idx] == '0') {
            return 0;
        } else if (idx >= n) {
            return 1;
        }

        if (dp[idx] != -1) return dp[idx];

        int ways = decode(s, idx+1, n, dp);

        if (idx+1 < n && ((s[idx] == '1') || (s[idx] == '2' && s[idx+1] <= '6'))) {
            ways += decode(s, idx+2, n, dp);
        }

        return dp[idx] = ways;
    }

    int numDecodings(string s) {
        int n = s.length();
        int dp[n+1];
        fill_n(dp, n, -1);
        return decode(s, 0, n, dp);
    }
};