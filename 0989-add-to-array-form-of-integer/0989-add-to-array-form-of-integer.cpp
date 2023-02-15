class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i=num.size()-1;
        stack<int>s;
        int carry=0;
        while(k!=0||i>=0||carry>0)
        {
            if(i>=0){
                int a=(num[i]+(k%10)+carry)%10;
                carry=(num[i]+(k%10)+carry)/10;
                k/=10;
                s.push(a);
                i--;
            }
            else if(k>0)
            {
                int a=((k%10)+carry)%10;
                carry=((k%10)+carry)/10;
                k/=10;
                s.push(a);
            }
            else if(carry>0)
            {
                s.push(carry);
                carry=0;
            }
        }
        vector<int>ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};