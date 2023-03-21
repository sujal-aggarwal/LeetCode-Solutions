class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long i=0;
        long long j=0;
        int n=nums.size();
        long long total_zero=0;
        while(j<n&&i<n){
            while(i<n&&nums[i]!=0){
                i++;
            }
            if(i>=n)break;
            j=i;
            while(j<n&&nums[j]==0){
                j++;
            }
            j--;
            if(j>=i&&nums[j]==0){
                long long length=j-i+1;
                total_zero+=(length*(length+1))/2;
            }
            i=j+1;
        }
        return total_zero;
    }
};