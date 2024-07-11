class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        string ans="";
        stack<int>st;
        vector<int>Pair(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                int index=st.top();
                st.pop();
                Pair[index]=i;
                Pair[i]=index;
            }
        }
        for(int currentIndex=0,direction=1;currentIndex<n;currentIndex+=direction){
            if(s[currentIndex]=='(' || s[currentIndex]==')'){
                currentIndex=Pair[currentIndex];
                direction=-direction;
            }else{
                ans+=s[currentIndex];
            }
        }
        return ans;
    }
};
// class Solution {
// public:
//     string reverseParentheses(string s) {
//         string ans="";
//         vector<int>reverseIndex;
//         for(auto ch:s){
//             if(ch=='('){
//                 reverseIndex.push_back(ans.size());
//             }else if(ch==')'){
//                 reverse(ans.begin()+reverseIndex.back(),ans.end());
//                 reverseIndex.pop_back();
//             }else{
//                 ans+=ch;
//             }
//         }
//         return ans;
//     }
// };