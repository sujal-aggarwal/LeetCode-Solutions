class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(auto i:s){
            if(st.empty()||st.top().first!=i){
                st.push({i,1});
            }
            else if(st.top().first==i){
                int a=st.top().second+1;
                if(a==k){
                    a--;
                    while(a--){
                        st.pop();
                    }
                }else{
                    st.push({i,a});
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};