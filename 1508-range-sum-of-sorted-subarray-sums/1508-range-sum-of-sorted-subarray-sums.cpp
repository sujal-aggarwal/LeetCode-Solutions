class Solution {
public:
    int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>v;
        for(int i=0;i<n;i++){
            int curr=0;
            for(int j=i;j<n;j++){
                curr+=nums[j];
                v.push_back(curr);
            }
        }
        sort(v.begin(),v.end());
        int sum=0;
        for(int i=left-1;i<right;i++){
            sum=(sum + v[i]%mod + 0LL)%mod;
        }
        return sum;
    }
};