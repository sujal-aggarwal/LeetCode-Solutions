class Solution {
public:
    string reverseParentheses(string s) {
        string ans="";
        vector<int>reverseIndex;
        for(auto ch:s){
            if(ch=='('){
                reverseIndex.push_back(ans.size());
            }else if(ch==')'){
                reverse(ans.begin()+reverseIndex.back(),ans.end());
                reverseIndex.pop_back();
            }else{
                ans+=ch;
            }
        }
        return ans;
    }
};