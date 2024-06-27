// class Solution {
// public:
//     int minimumTime(string s) {
//         int n=s.length();
//         vector<int>left(n,0);
//         vector<int>right(n,0);
//         left[0]=((s[0]=='1')?1:0);
//         right[n-1]=(s[n-1]=='1')?1:0;
//         for(int i=1;i<n;i++){
//             if(s[i]=='1')
//                 left[i]=min(left[i-1]+2,i+1);
//             else
//                 left[i]=left[i-1];
//         }
//         for(int i=n-2;i>=0;i--){
//             if(s[i]=='1')
//                 right[i]=min(right[i+1]+2,n-i);
//             else
//                 right[i]=right[i+1];
//         }
//         int ans=min(left[n-1],right[0]);
//         for(int i=0;i<n-1;i++){
//             ans=min(ans,left[i]+right[i+1]);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = 1;  // REMOVE_FROM_LEFT
        dp[0][2] = 1;  // REMOVE_FROM_RIGHT
        dp[0][1] = (s[0] == '0') ? 0 : 2;  // LEAVE

        for (int i = 1; i < n; ++i) {
            dp[i][1] = ((s[i]=='0')?0:2) + min(dp[i - 1][1], dp[i - 1][0]);  // LEAVE
            dp[i][0] = 1 + dp[i - 1][0];  // REMOVE_FROM_LEFT
            dp[i][2] = 1 + min({dp[i - 1][0], dp[i - 1][2], dp[i - 1][1]});  // REMOVE_FROM_RIGHT
        }

        return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    }
};