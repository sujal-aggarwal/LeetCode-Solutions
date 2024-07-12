class Solution {
    int solve(string & s,string& pair, int score){
        stack<char>st;
        int res=0;
        for(auto i:s){
            if(i==pair[1] && !st.empty() && st.top()==pair[0]){
                st.pop();
                res+=score;
            }else{
                st.push(i);
            }
        }
        s.clear();
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(),s.end());
        return res;
    }
public:
    int maximumGain(string s, int x, int y) {
        int ans=0;
        string priority=(x>y)?"ab":"ba";
        ans+=solve(s,priority,max(x,y));
        reverse(priority.begin(),priority.end());
        ans+=solve(s,priority,min(x,y));
        return ans;
    }
};