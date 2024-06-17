class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        for(string s:strs){
            int i=0;
            int a=min(ans.length(),s.length());
            while(i<a){
                if(ans[i]==s[i]){
                    i++;
                    continue;
                }
                break;
            }
            ans=ans.substr(0,i);
        }
        return ans;
    }
};