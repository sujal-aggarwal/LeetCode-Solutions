class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        vector<long long>preSum(n,0);
        preSum[0]=chalk[0];
        for(int i=0;i<n;i++){
            if(i==0){
                preSum[i]=chalk[i];
            }else{
                preSum[i]=preSum[i-1]+chalk[i];
            }
            if(preSum[i]>k)return i;
        }
        k%=preSum[n-1];
        for(int i=0;i<n;i++){
            if(preSum[i]>k)return i;
        }
        return -1;
    }
};