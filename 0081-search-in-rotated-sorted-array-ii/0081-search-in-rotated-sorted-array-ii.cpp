class Solution {
public:
    bool sorted(vector<int>&nums,int&i){
        for(;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1])
                return false;
        }
        return true;
    }
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;
        if(sorted(nums,i)){
            int l=-1,r=n;
            while(r>l+1){
                int mid=(l+r)/2;
                if(nums[mid]<=target)
                    l=mid;
                else
                    r=mid;
            }
            if(l!=-1&&nums[l]==target)
                return true;
            return false;
        }
        else{
            int l=-1,r=i+1;
            while(r>l+1){
                int mid=(l+r)/2;
                if(nums[mid]<=target)
                    l=mid;
                else
                    r=mid;
            }
            if(l!=-1&&nums[l]==target)
                return true;
            int low=i,high=n;
             while(high>low+1){
                int mid=(low+high)/2;
                if(nums[mid]<=target)
                    low=mid;
                else
                    high=mid;
            }
            if(low!=-1&&nums[low]==target)
                return true;
        }
        return false;
    }
};