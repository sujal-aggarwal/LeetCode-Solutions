class Solution {
public:
    int findTheWinner(int n, int k) {
        int index=0;
        for(int i=1;i<n;i++){
            index+=k;
            index%=(i+1);
        }
        return index+1;
    }
};