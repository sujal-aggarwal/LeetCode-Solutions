class Solution {
public:
    bool isPalindrome(int x) {
        stringstream ss;
        ss<<x;
        string a;
        ss>>a;
        long long y;
        reverse(a.begin(),a.end());
        ss.clear();
        ss<<a;
        ss>>y;
        cout<<x<<" "<<y<<endl;
        return x==y;
    }
};