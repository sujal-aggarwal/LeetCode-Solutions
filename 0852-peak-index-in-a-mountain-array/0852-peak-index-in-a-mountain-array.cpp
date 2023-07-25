class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=0,r=n-1;
        while(r>l+1){
            int mid=l+(r-l)/2;
            if(arr[mid]>arr[mid+1]&&arr[mid-1]<arr[mid]){
                return mid;
            }
            else if(arr[mid]>arr[mid+1]&&arr[mid-1]>arr[mid]){
                r=mid;
            }else if(arr[mid]<arr[mid+1]&&arr[mid-1]<arr[mid]){
                l=mid;
            }
        }
        return 0;
    }
};