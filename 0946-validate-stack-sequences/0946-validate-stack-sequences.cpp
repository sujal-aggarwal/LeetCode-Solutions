class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int index=0;
        for(auto i:pushed){
            st.push(i);
            while(!st.empty()&&index<popped.size()&&st.top()==popped[index]){
                st.pop();
                index++;
            } 
        }
        return index==popped.size();
    }
};