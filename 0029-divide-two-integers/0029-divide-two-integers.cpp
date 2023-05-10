class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==1){
            return dividend;
        }
        if(divisor==-1){
            if(dividend==-2147483648){
                return 2147483647;
            }
            return -1*dividend;
        }
        long long a=abs(dividend);
        long long b=abs(divisor);
        long long sum=b;
        int count=0;
        while(sum<=a)
        {
            // if(count<2147483647)
                count++;
            sum+=b;
        }
        if(dividend<0&&divisor<0)
            return count;
        else if(dividend<0||divisor<0)
            return count*-1;
        return count;
    }
};