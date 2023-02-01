class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str2.size()<str1.size())
            swap(str2,str1);
        int m=str1.size();
        int n=str2.size();
        if(str1+str2!=str2+str1)
            return "";
        int k=__gcd(m,n);
        string g=str1.substr(0,k);
        return g;
    }
};