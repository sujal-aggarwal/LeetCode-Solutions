class Solution {
public:
    string removeStars(string s) {
        string st="";
        for(int j=0;j<s.size();j++){
            if(s[j]=='*'){
                st.pop_back();
            }else{
                st.push_back(s[j]);
            }
        }
        return st;
    }
};