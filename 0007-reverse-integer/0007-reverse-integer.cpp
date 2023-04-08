class Solution {
public:
    int reverse(int x) {
        long long a=0;
        if(x>=0){
            while(x>0){
                a=(a*10)+(x%10);
                x/=10;
            }
            if(a>INT_MAX){
                return 0;
            }else{
                return a;
            }
        }else{
            x=abs(x);
            while(x>0){
                a=(a*10)+(x%10);
                x/=10;
            }
            a*=-1;
            if(a<INT_MIN){
                return 0;
            }else{
                return a;
            }
        }
    }
};