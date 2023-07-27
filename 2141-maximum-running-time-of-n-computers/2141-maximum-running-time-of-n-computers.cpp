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
        ll l=*min_element(a.begin(),a.end());
        ll r=accumulate(a.begin(),a.end(),0LL)/n;
        ll res=0;
        while(r>=l){
            ll mid=l+(r-l)/2;
            if(check(a,mid,n)){
                res=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return res;
    }
};