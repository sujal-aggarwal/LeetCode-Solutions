class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int size=0;
        vector<int>v(256,0);
        while(right<s.size())
        {
            v[s[right]]++;
            if(v[s[right]]>1)
            {
                size=max(size,right-left);
                while(v[s[right]]>1){
                    v[s[left]]--;
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