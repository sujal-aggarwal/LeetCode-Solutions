class Solution {
public:
    string reverseStr(string s, int k) {
        if(s.size()<=k){ reverse(s.begin(),s.end()); return s;}
        if(s.size()>k && s.size()<=(2*k)){ reverse(s.begin(),s.begin()+k); return s;}
        reverse(s.begin(),s.begin()+k);
        return s.substr(0,2*k) + reverseStr(s.substr(2*k),k);
    }
};