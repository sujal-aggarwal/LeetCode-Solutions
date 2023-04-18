class Solution {
public:
    string mergeAlternately(string text1, string text2) {
        string s="";
        int i=0;
        for(;i<text1.size();i++){
            s+=text1[i];
            if(i<text2.size()){
                s+=text2[i];
            }
        }
        while(i<text2.size()){
            s+=text2[i];
            i++;
        }
        return s;
    }
};