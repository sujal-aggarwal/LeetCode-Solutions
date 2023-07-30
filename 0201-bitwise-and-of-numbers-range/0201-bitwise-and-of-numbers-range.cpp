class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt=0;
        while(left>0||right>0){
            if(right==left)return left<<cnt;
            left=left>>1;
            right=right>>1;
            cnt++;
        }
        return 0;
    }
};