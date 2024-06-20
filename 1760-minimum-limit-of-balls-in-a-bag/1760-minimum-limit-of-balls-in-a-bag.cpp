class Solution {
public:
    int n;
    bool isPossible(vector<int>&nums,int maxOperations, int maxPenalty){
        int count=0;
        for(int i=0;i<n;i++){
            count+=(nums[i]/maxPenalty);
            if(nums[i]%maxPenalty==0)count--;
        }
        return count<=maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        n=nums.size();
        int minPenalty=1;
        int maxPenalty=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(minPenalty<=maxPenalty){
            int midPenalty=minPenalty + (maxPenalty-minPenalty)/2;
            if(isPossible(nums,maxOperations,midPenalty)){
                ans=midPenalty;
                maxPenalty=midPenalty-1;
            }
            else{
                minPenalty=midPenalty+1;
            }
        }
        return ans;
    }
};