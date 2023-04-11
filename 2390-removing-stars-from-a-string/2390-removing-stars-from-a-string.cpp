class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(auto i:s){
            if(i=='*'){
                st.pop();
            }else{
                st.push(i);
            }
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};