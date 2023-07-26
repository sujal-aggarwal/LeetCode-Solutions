class Solution {
public:
    vector<string>result;
    void solve(string ans,int n,int m){
        if(n==0){
            while(m--){
                ans.push_back(')');
            }
            result.push_back(ans);
            return;
        }
        if(n){
            solve(ans+"(",n-1,m);
        }
        if(m>n){
            solve(ans+")",n,m-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp;
        solve(temp,n,n);
        return result;
    }
};