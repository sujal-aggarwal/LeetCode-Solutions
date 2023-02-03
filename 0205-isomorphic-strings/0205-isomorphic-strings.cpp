class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>mp_stot;
        map<char,char>mp_ttos;
        for(int i=0;i<t.size();i++)
        {
            if(mp_stot.count(s[i])>0)
            {
                if(mp_stot[s[i]]!=t[i])
                    return false;
            }
            if(mp_ttos.count(t[i])>0)
            {
                if(mp_ttos[t[i]]!=s[i])
                    return false;
            }
            mp_stot[s[i]]=t[i];
            mp_ttos[t[i]]=s[i];
        }
        return true;
    }
};