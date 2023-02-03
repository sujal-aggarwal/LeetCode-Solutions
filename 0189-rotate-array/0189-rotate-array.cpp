class Solution {
public:
    void two_pointer_rotate(vector<int>&nums,int i,int j)
    {
        while(i<j)
        {
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>=n)
            k=k%n;
        if(k==0||n==1)
            return ;
        two_pointer_rotate(nums,0,n-1);
        two_pointer_rotate(nums,0,k-1);
        two_pointer_rotate(nums,k,n-1);
    }
};