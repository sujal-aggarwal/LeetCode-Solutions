class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        int b_left=0;
        int a_right=0;
        for(int i=0;i<n;i++){
            if(s[i]=='b')b_left++;
        }
        int ans=INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='b')b_left--;
            ans=min(ans,a_right+b_left);
            if(s[i]=='a')a_right++;
        }
        return ans;
    }
};