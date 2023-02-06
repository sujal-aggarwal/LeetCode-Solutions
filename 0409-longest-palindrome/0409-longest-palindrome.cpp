class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        int odd=0;
        int length=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            int freq=it->second;
            length+=(freq-(freq%2));
            odd+=(freq%2);
        }
        if(odd)
            length++;
        return length;
    }
};