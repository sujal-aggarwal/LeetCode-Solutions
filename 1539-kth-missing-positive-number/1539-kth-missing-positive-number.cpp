class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int l=-1,r=n;
        while(r>l+1){
            int mid=l+(r-l)/2;
            if(arr[mid]-(mid+1)>=k){
                r=mid;
            }else{
                l=mid;
            }
        }
        return l+1+k;
    }
};