class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        int target=nums[0];
        int count=1;
        for(int i=1;i<n;i++){
            if(count==0){
                target=nums[i];
                count=1;
            }else if(nums[i]!=target)count--;
            else if(nums[i]==target)count++;
        }
        int totalFreq=0;
        for(int i:nums){
            if(target==i)totalFreq++;
        }
        int currFreq=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]==target){
                currFreq++;
            }
            int rightFreq=totalFreq-currFreq;
            if(currFreq*2 > i+1 && rightFreq*2 > n-i-1)return i;
        }
        return -1;
    }
};