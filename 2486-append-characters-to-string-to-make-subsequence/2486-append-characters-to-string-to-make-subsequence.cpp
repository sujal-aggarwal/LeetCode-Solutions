class Solution {
public:
    int appendCharacters(string s, string t) {
        int index_t=0;
        int index_s=0;
        while(index_s<s.size()){
            if(s[index_s]==t[index_t] && index_t<t.size()){
                index_t++;
            }
            index_s++;
        }
        return t.size()-index_t;
    }
};