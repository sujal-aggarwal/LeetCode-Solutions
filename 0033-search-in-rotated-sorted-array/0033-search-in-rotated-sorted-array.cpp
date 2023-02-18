class Solution {
public:
    int search(vector<int>& nums, int target) {
        int end=nums[nums.size()-1];
        int l=-1,r=nums.size();
        while(r>l+1){
            int mid=(l+r)/2;
            if(nums[mid]<=end){
                r=mid;
            }else{
                l=mid;
            }
        }
        if(l==-1){
            int l=-1,r=nums.size();
            while(r>l+1){
                int mid=(l+r)/2;
                if(nums[mid]<=target){
                    l=mid;
                }else{
                    r=mid;
                }
            }
            if(l!=-1&&nums[l]==target)
                return l;
            return -1;
        }
        if(target>=nums[r]&&target<=end){
            int low=r-1,high=nums.size();
            while(high>low+1){
                int mid=(low+high)/2;
                if(nums[mid]<=target)
                    low=mid;
                else
                    high=mid;
            }
            if(low!=r-1&&nums[low]==target)
                return low;
            return -1;
        }else if(target<=nums[l]&&target>=nums[0]){
             int low=-1,high=l+1;
                while(high>low+1){
                    int mid=(low+high)/2;
                    if(nums[mid]<=target)
                        low=mid;
                    else
                        high=mid;
                }
                if(low!=-1&&nums[low]==target)
                    return low;
                return -1;
        }
        return -1;
    }
};