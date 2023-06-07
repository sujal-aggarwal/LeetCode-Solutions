class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=0;
        while(a>0||b>0||c>0){
            int a_bit=a%2,b_bit=b%2,c_bit=c%2;
            a>>=1;
            b>>=1;
            c>>=1;
            if((a_bit|b_bit)==c_bit){continue;}
            if(c_bit==1){
                cnt+=1;
            }else{
                if(a_bit==1&&b_bit==1){cnt+=2;}
                else{cnt++;}
            }
        }
        return cnt;
    }
};