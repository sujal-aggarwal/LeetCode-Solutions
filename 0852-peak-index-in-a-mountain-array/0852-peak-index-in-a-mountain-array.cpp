class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=1,r=n-2;
        while(r>=l){
            int mid=l+(r-l)/2;
            if(arr[mid]>arr[mid+1]&&arr[mid-1]<arr[mid]){
                return mid;
            }
            else if(arr[mid]>arr[mid+1]&&arr[mid-1]>arr[mid]){
                r=mid;
            }else if(arr[mid]<arr[mid+1]&&arr[mid-1]<arr[mid]){
                l=mid+1;
            }
        }
        return 0;
    }
};