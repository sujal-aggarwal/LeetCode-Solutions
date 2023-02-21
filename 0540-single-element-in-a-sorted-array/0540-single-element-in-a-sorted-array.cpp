class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=-1,r=nums.size();
        while(r>l+1){
            int mid=l+(r-l)/2;
            if((mid%2==0&&mid<nums.size()-1&&nums[mid]==nums[mid+1])||(mid%2!=0&&mid>=0&&nums[mid]==nums[mid-1])){
                l=mid;
            }
            else
                r=mid;
        }
        cout<<l<<" "<<r<<endl;
        return nums[r];
    }
};