class Solution {
public:
    int divide(int dvd, int dis) {
        if(dis==1){
            return dvd;
        }
        if(dis==-1){
            if(dvd==INT_MIN){
                return INT_MAX;
            }
            return -1*dvd;
        }
        int sign = ((dvd<0)^(dis<0))?-1:1;
        unsigned int dividend=abs(dvd);
        unsigned int divisor=abs(dis);
        long long quotient=0;
        while(dividend>=divisor)
        {
            long long temp=divisor;
            int p=0;
            while((temp<<1)<=dividend){
                temp=temp<<1;
                p++;
            }
            dividend-=temp;
            quotient+=1<<p;
        }
        return quotient*sign;
    }
};