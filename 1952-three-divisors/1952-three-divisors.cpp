class Solution {
public:
    bool prime(int n)
    {
        for(int i=2;i*i<=n;i++)
            if(n%i==0)return false;
        return true;
    }
    bool isThree(int n) {
        if(prime(n))
            return false;
        int count =0;
        for(int i=2;i<n;i++){
            if(n%i==0)
                count++;
            if(count>1)
                return false;
        }
        return true;
    }
};