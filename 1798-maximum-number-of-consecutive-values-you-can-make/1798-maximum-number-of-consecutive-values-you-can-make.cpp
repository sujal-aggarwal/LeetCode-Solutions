class Solution {
public:
    int n;
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        n=coins.size();
        int reach=0;
        for(int i=0;i<n;i++){
            if(coins[i]<=reach+1){
                reach+=coins[i];
            }else{
                break;
            }
        }
        return reach+1;
    }
};