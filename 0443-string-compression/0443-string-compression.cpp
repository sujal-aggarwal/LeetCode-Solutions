class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";
        s+=chars[0];
        char prev=chars[0];
        int count=1;
        for(int j=1;j<chars.size();j++){
            char i=chars[j];
            if(i==prev){
                count++;
            }
            else{
                if(count>1)
                    s+=to_string(count);
                count=1;
                s+=i;
                prev=i;
            }
        }
        if(count){
            if(count>1)
                s+=to_string(count);
        }
        int k=0;
        for(auto i:s){
            chars[k]=i;
            k++;
        }
        return s.size();
    }
};