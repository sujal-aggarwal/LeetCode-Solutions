class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        sort(happiness.begin(),happiness.end());
        long long sum=0;
        int count=0;
        for(int i=n-1;i>=n-k;i--){
            if(happiness[i]>=count){
                sum+=happiness[i]-count;
                count++;
            }else{
                break;
            }
        }
        return sum;
    }
};