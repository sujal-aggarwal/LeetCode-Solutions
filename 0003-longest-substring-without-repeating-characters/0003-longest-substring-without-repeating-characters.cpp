class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int size=0;
        map<char,int>mp;
        while(right<s.size())
        {
            mp[s[right]]++;
            if(mp[s[right]]>1)
            {
                size=max(size,right-left);
                while(mp[s[right]]>1){
                    mp[s[left]]--;
                    left++;
                }
                right++;
                continue;
            }
            size=max(size,right-left+1);
            right++;
        }
        return size;
    }
};