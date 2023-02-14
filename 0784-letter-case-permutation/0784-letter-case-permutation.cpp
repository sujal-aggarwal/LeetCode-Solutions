class Solution {
public:
    void recursion(vector<string> &arr, string ans, string s, int index)
    {
        if (index == s.size())
        {
            arr.push_back(ans);
            return;
        }
        if (s[index] >= '0' && s[index] <= '9')
        {
            ans += s[index];
            recursion(arr, ans, s, index + 1);
        }
        else
        {
            string ans2 = ans;
            ans2 += s[index];
            recursion(arr, ans2, s, index + 1);
            if (s[index] >= 'A' && s[index] <= 'Z')
            {
                string ans3 = ans;
                ans3 += (s[index] - 'A' + 'a');
                recursion(arr, ans3, s, index + 1);
                return;
            }
            else
            {
                string ans4 = ans;
                ans4 += (s[index] - 'a' + 'A');
                recursion(arr, ans4, s, index + 1);
                return;
            }
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        recursion(ans,"",s,0);
        return ans;
    }
};