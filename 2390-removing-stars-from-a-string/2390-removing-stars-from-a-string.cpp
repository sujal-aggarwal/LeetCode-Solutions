class Solution {
public:
    string removeStars(string s) {
        string st="";
        for(auto i:s){
            if(i=='*'){
                st.pop_back();
            }else{
                st.push_back(i);
            }
        }
        return st;
    }
};