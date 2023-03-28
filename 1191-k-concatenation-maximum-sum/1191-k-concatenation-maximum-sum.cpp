class Solution {
public:
    #define mod 1000000007
    int Kadane(vector<int>&arr){
        int best_so_far=0,curr_best=0;
        for(auto i:arr){
            curr_best+=i;
            if(curr_best>best_so_far){best_so_far=curr_best;}
            if(curr_best<0){curr_best=0;}
        }
        return best_so_far;
    }
    int Prefix(vector<int>&arr){
        int best=0,curr=0;
        for(auto i:arr){
            curr+=i;
            if(best<curr){best=curr;}
        }
        return best;
    }
    int Suffix(vector<int>&arr){
        int best=0,curr=0;
        for(int i=arr.size()-1;i>=0;i--){
            curr+=arr[i];
            if(best<curr){best=curr;}
        }
        return best;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int sum=accumulate(arr.begin(),arr.end(),0);
        if(k>=2){
            if(sum>0){
                return (((k-2)*(long)sum)%mod+Prefix(arr)%mod+Suffix(arr)%mod)%mod;
            }else{
                return max(Prefix(arr)+Suffix(arr),Kadane(arr));
            }
        }
        return Kadane(arr);
    }
};