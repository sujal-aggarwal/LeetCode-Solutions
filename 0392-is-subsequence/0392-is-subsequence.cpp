class Solution {
public:
    bool isSubsequence(string s, string t) {
        for(int i=0;i<t.size();i++)
        {
            if(!s.empty()){
                if(s[0]==t[i])
                {
                    s=s.substr(1);
                }
            }
        }
        if(s.empty())
            return true;
        return false;
    }
};