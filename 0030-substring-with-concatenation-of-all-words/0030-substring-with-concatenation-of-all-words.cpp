class Solution {
public:
    int window_size,word_size,n;
    vector<int> findSubstring(string s, vector<string>& words) {
        word_size=words[0].size();
        n=words.size();
        window_size=n*word_size;
        if(window_size>s.size())
            return vector<int>();
        vector<int>arr;
        
        //Making map for storing each word frequency
        unordered_map<string,int>mp;
        for(int i=0;i<window_size;i+=word_size)
        {
            mp[s.substr(i,word_size)]++;
        }
        
        //
        int left=0,right=window_size-1;
        while(right<s.size())
        {
            
            //Checking if the words are found in the map
            bool found=true;
            for(int i=0;i<n;i++)
            {
                if(mp[words[i]]==0){
                    found= false;break;
                }
                mp[words[i]]--;
            }
            if(found){
                arr.push_back(left);
            }
            
            
            //Reassigning map
            mp.clear();
            right++;
            left++;
            for(int i=left,j=0;j<window_size;i+=word_size,j+=word_size)
            {
                mp[s.substr(i,word_size)]++;
            }
        }
        return arr;
    }
};