#define ll long long
class Solution {
public:
    ll n;
    int minSubarray(vector<int>& nums, int p) {
        n=nums.size();
        ll sum=0;
        for(ll i=0;i<n;i++){
            sum+=nums[i];
            sum%=p;
        }
        if(sum==0){
            return 0;
        }
        ll target=sum;
        ll s=0;
        ll min_length=n;
        unordered_map<ll,ll>mp;
        mp[0]=-1;
        for(ll i=0;i<n;i++){
            nums[i]=(nums[i]+s)%p;
            s=nums[i];
            if(mp.find((nums[i]-target+p)%p)!=mp.end()){
                min_length=min(min_length,i-mp[(nums[i]-target+p)%p]);
            }
            mp[nums[i]]=i;
        }
        return min_length==n?-1:min_length;
    }
};