#define ll long long
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i=0;
        ll maxreach=0;
        int ans=0;
        while(maxreach<n){
            if(i<nums.size() && nums[i]<=maxreach+1){
                maxreach+=nums[i];
                i++;
            }else{
                maxreach+=(maxreach+1);
                ans++;
            }
        }
        return ans;
    }
};