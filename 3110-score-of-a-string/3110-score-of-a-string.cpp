class Solution {
public:
    int scoreOfString(string s) {
        int index=0;
        return accumulate(s.begin()+1, s.end(), 0, [&s,&index](int total, char c) mutable {
            return total + abs(s[index++] - c);
        });
    }
};