#define ll long long
class Solution {
public:
    int solve(vector<int>&arr,int day,int k){
        int adj=0;
        int count=0;
        for(int i:arr){
            if(i<=day){
                adj++;
            }else{
                adj=0;
            }
            if(adj==k){
                count++;
                adj=0;
            }
        }
        return count;
    }
    int minDays(vector<int>& arr, int m, int k) {
        ll l=0,r=*max_element(arr.begin(),arr.end());
        int ans=-1;
        while(r>=l){
            int mid=(l+r)/2;
            int a=solve(arr,mid,k);
            if(a>=m){ans=mid;r=mid-1;}
            else l=mid+1;
        }
        return ans;
    }
};