#define ll long long
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prev=0;
        for_each(nums.begin(),nums.end(),[=,&prev](int& current_val){
            current_val=(current_val%k+prev%k)%k;
            prev=current_val;
        });
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                if(i-mp[nums[i]]>1){
                    return true;
                }
            }else{
                mp[nums[i]]=i;
            }
        }
        return false;
    }
};