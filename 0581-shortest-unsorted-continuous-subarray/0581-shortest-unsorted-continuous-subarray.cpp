class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>arr=nums;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            arr[i]-=nums[i];
        }
        int min_index=INT_MIN,max_index=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=0&&min_index==INT_MIN){
                min_index=i;
            }else if(arr[i]!=0){
                max_index=max(max_index,i);
            }
        }
        if(min_index==INT_MIN)return 0;
        if(max_index==INT_MIN)return 1;
        return max_index-min_index+1;
    }
};