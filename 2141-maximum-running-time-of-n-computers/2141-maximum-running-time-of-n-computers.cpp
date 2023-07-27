class Solution {
public:
    typedef long long ll;
    bool check(vector<int>&batteries,ll time,ll n){
        ll total=time*n;
        for(ll i=0;i<batteries.size();i++){
            total-=min((ll)batteries[i],time);
            if(total<=0)return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& a) {
        ll l=*min_element(a.begin(),a.end())-1;
        ll r=accumulate(a.begin(),a.end(),0LL)/n;
        r++;
        while(r>l+1){
            ll mid=l+(r-l)/2;
            if(check(a,mid,n)){
                l=mid;
            }else{
                r=mid;
            }
        }
        return l;
    }
};