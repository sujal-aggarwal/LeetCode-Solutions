class Solution {
public:
    vector<int>arr;
    int val(int si,int ei){
        return arr[ei]-arr[si];
    }
    int minDifference(vector<int>& nums) {
        arr=nums;
        int n =arr.size();
        if(n<4)return 0;
        sort(arr.begin(),arr.end());
        return min({val(0,n-4),val(1,n-3),val(2,n-2),val(3,n-1)});
        
    }
};