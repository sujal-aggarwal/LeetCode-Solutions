// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=-1,r=n;
        while(r>l+1)
        {
            int m;
            if(l==-1&&n==2147483647)
            {
                m=(n-1)/2;
            }
            else
                m=l+(r-l)/2;
            if(isBadVersion(m))
                r=m;
            else
                l=m;
        }
        return r;
    }
};