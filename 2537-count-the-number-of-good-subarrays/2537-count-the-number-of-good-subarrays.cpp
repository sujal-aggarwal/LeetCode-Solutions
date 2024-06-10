#define ll long long int
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        ll n = nums.size();
        ll i=0;
        map<ll,ll>m;
        ll total = 0;
        ll j=0;
        ll ans = 0;
        map<ll,ll>check;
        while(j<n){
            
            m[nums[j]]++;
            ll curr = m[nums[j]]*(m[nums[j]]-1)/2;
           total += m[nums[j]]-1; 
            while(i<j && total>=k){
                ans++;
                 ans += (n-j-1);
               total = total -  (m[nums[i]]-1);
                m[nums[i]]--;
                i++;
            }
            j++;
        } 
        return ans;
    }
};