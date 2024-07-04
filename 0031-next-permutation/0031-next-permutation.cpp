class Solution {
public:
    int n;
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return;
        if(nums[n-1]>nums[n-2]){
            swap(nums[n-1],nums[n-2]);
            return ;
        }
        int i=n-1;
        while(i>0){
            if(nums[i-1]>=nums[i])i--;
            else break;
        }
        // cout<<"i "<<i<<" "<<nums[i]<<endl;
        if(i==0){
            sort(nums.begin(),nums.end());
            return;
        }
        int target = nums[i-1];
        // cout<<"target "<<target<<endl;
        int l=i,r=n-1;
        int index=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]<=target){
                r=mid-1;
            }else{
                l=mid+1;
                index=mid;
            }
        }
        // cout<<"index "<<index<<" "<<nums[index]<<endl;
        swap(nums[i-1],nums[index]);
        // for(int i=0;i<n;i++){
        //     cout<<nums[i]<<" ";
        // }
        // cout<<endl;
        sort(nums.begin()+i,nums.end());
    } 
};