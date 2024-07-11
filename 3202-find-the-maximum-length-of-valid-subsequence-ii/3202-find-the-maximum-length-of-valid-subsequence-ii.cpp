class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        vector dp(k,vector<int>(k,0));
        for(int num:nums){
            int currNum=num%k;
            for(int mod=0;mod<k;mod++){
                int prevNum=(k+mod-currNum)%k;
                dp[currNum][mod]=max(dp[currNum][mod],1+dp[prevNum][mod]);
                ans=max(ans,dp[currNum][mod]);
            }
        }
        return ans;
    }
};
// class Solution {
// public:
//     int maximumLength(vector<int>& nums, int k) {
//         int n=nums.size();
//         for_each(nums.begin(),nums.end(),[=](int& current_value){
//             current_value%=k;
//         });
//         int ans=0;
//         for(int modulo=0;modulo<k;modulo++){
//             vector<int>dp(n,1);
//             unordered_map<int,int>mp;
//             for(int index=0;index<n;index++){
//                 int curr_val=nums[index];
//                 if(modulo-curr_val>=0){
//                     int target=modulo-curr_val;
//                     if((mp.find(target))!=mp.end()){
//                         int length=dp[mp[target]];
//                         length++;
//                         dp[index]=length;
//                         ans=max(length,ans);
//                     }
//                 }else{
//                     int target=k+modulo-curr_val;
//                     if((mp.find(target))!=mp.end()){
//                         int length=dp[mp[target]];
//                         length++;
//                         dp[index]=length;
//                         ans=max(length,ans);
//                     }
//                 }
//                 mp[curr_val]=index;
//             }
//         }
//         return ans;
//     }
// };