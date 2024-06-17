#define ll long long
class Solution {
public:
    ll sum(ll i,ll j){
        return i*i + j*j;
    }
    bool judgeSquareSum(int c) {
        if(ceil(sqrt(c))==floor(sqrt(c)))return true;
        ll r=floor(sqrt(c));
        ll l=0;
        while(l<=r){
            ll a=sum(l,r);
            if(a==c)return true;
            if(a>c){
                r--;
                l--;
            }
            l++;
        }
        return false;
    }
};