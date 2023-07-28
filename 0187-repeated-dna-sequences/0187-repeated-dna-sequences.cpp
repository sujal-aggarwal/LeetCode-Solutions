class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        if(n<10)return {};
        vector<string>ans;
        unordered_map<string,int>mp;
        int i=0,j=9;
        string k=s.substr(0,10);
        while(j<n){
            if(mp.count(k)){
                if(mp[k]==1)
                    ans.push_back(k);
                mp[k]++;
            }else{
                mp[k]++;
            }
            k.erase(0,1);
            if(j+1<n){
                k+=s[j+1];
            }
            j++;
        }
        return ans;
    }
};