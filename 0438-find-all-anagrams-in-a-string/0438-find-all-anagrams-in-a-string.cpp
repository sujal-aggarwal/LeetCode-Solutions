class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        if(s.length()<p.length())
            return vector<int>();
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(int i=0;i<p.length();i++)
            freq2[p[i]-'a']++;
        int i=0;
        int j=0;
        while(j<s.length())
        {
            if(j-i+1<p.length())
            {
                freq1[s[j]-'a']++;
                j++;
                continue;
            }
            freq1[s[j]-'a']++;
            if(freq1==freq2)
            {
                ans.push_back(i);
            }
            freq1[s[i]-'a']--;
            i++;
            j++;
        }
        return ans;
    }
};