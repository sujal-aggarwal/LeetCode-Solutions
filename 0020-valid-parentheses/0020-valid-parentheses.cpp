class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto i:s){
            if(i==']'||i=='}'||i==')'){
                if(!st.empty()&&(st.top()+1==i||st.top()+2==i)){
                    st.pop();
                }else{
                    return false;
                }
                continue;
            }
            st.push(i);
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};