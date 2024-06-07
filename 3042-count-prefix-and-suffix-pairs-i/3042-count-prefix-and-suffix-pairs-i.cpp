class Solution {
public:
    bool isPrefix(string& st1,string& st2){
        int i=0,j=0;
        if(st1.size()>st2.size())return false;
        while(i<st1.size()){
            if(st1[i++]!=st2[j++]){
                return false;
            }
        }
        return true;
    }
    bool isSuffix(string st1,string st2){
        reverse(st1.begin(),st1.end());
        reverse(st2.begin(),st2.end());
        return isPrefix(st1,st2);
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                count+=((isPrefix(words[i],words[j])&&isSuffix(words[i],words[j]))?1:0);
            }
        }
        return count;
    }
};