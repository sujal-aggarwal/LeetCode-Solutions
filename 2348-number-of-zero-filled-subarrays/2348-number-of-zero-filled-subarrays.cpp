class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long total_zero=0;
        long long count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count++;
            }else{
                total_zero+=(count*(count+1))/2;
                count=0;
            }
        }                
        total_zero+=(count*(count+1))/2;
        return total_zero;
    }
};