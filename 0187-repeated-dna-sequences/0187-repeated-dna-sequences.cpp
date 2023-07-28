class Solution {
public:
    void add_bit(char ch,int&bit){
        bit=bit<<2;
        if(ch=='C')bit=bit|1;
        if(ch=='G')bit=bit|2;
        if(ch=='T')bit=bit|3;
    }
    int bit(string&s,int idx){
        int bit=0;
        for(int i=0;i<10;i++){
            add_bit(s[idx+i],bit);
        }
        return bit;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        
        if(n<10)return {};
        
        vector<string>ans;
        unordered_map<int,int>mp;
        
        for(int i=0;(i+10)<=n;i++){
            int key=bit(s,i);
            if(mp[key]==1){
                ans.push_back(s.substr(i,10));
            }
            mp[key]++;
        }
        
        return ans;
    }
};