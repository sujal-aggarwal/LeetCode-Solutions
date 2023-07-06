class Solution {
public:
    bool valid(int target,vector<int>&nums,int l){
        int i=0,j=0,sum=0;
        while(j-i+1<=l){
            sum+=nums[j];
            j++;
        }
        if(sum>=target)return true;
        while(j<nums.size()){
            sum-=nums[i];
            i++;
            sum+=nums[j];
            j++;
            if(sum>=target)return true;
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=-1,r=n+1,length=INT_MAX;
        while(r>l+1){
            int mid=l+(r-l)/2;
            if(valid(target,nums,mid)){
                length=min(mid,length);
                r=mid;
            }else{
                l=mid;
            }
        }
        return (length==INT_MAX)?0:length;
    }
};