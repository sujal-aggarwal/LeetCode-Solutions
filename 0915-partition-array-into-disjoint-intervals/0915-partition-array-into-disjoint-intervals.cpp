class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n,0);
        vector<int>right(left);
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=min(right[i+1],nums[i]);
        }
        for(int i=1;i<n;i++){
            if(left[i-1]<=right[i]){
                return i;
            }
        }
        return 0;
    }
};