class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long bit=1;
        int ans=0;
        for(int i=columnTitle.size()-1;i>=0;i--){
            ans+=(bit*(columnTitle[i]-'A'+1));
            bit*=26;
        }
        return ans;
    }
};