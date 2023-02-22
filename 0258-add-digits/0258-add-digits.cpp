class Solution {
public:
    long long sumofdigits(long long num){
        long long sum=0;
        while(num!=0){
            sum+=(num%10);
            num/=10;
        }
        return sum;
    }
    int addDigits(long long num) {
        long long a=sumofdigits(num);
        if(a==num)
            return a;
        return addDigits(a);
    }
};