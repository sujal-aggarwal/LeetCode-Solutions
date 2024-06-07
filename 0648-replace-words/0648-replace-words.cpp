class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,int>mp;
        for(string s:dictionary){
            mp[s]++;
        }
        vector<string> ans;
        stringstream str(sentence);
        string word;
        while(str >> word){
            ans.push_back(word);
        }
        for(string& s:ans){
            string k="";
            for(auto i:s){
                k+=i;
                if(mp.find(k)!=mp.end()){
                    break;
                }
            }
            s=k;
        }
        string s;
        for(string i:ans){
            s+=i;
            s+=" ";
        }
        s.pop_back();
        return s;
    }
};