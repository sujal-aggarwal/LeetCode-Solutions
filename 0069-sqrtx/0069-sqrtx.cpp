class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return 0;
        if(x<=3)
            return 1;
        long long i=2;
        for(;i*i<=x;i++)
            continue;
        i--;
        return i;
    }
};