#define ll long long
class Solution {
public:
    ll mod=1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i:nums){
            pq.push(i%mod);
        }
        while(k--){
            ll a=pq.top();
            pq.pop();
            pq.push((a+1)%mod);
        }
        ll ans=1;
        while(!pq.empty()){
            ll a=pq.top();
            ans=(ans%mod*a%mod)%mod;
            pq.pop();
        }
        return ans;
    }
};