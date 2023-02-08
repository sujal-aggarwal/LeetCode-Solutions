class Solution {
public:
    int window_size,word_size,n;
    bool found(string s,vector<string>&words)
    {
        unordered_map<string,int>mp;
        for(int i=0;i<s.size();i+=word_size)
        {
            mp[s.substr(i,word_size)]++;
        }
        for(int i=0;i<n;i++)
        {
            if(mp[words[i]]==0)
                return false;
            mp[words[i]]--;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        word_size=words[0].size();
        n=words.size();
        window_size=n*word_size;
        if(window_size>s.size())
            return vector<int>();
        vector<int>arr;
        int left=0,right=window_size-1;
        while(right<s.size())
        {
            if(found(s.substr(left,window_size),words)){
                arr.push_back(left);
            }
            right++;
            left++;
        }
        return arr;
    }
};