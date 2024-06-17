#define ll long long
class Solution {
public:
    bool solve(int n){
        ll l=0,r=n;
        while(r>=l){
            ll mid=(r+l)/2;
            if(mid*mid>n){
                r=mid-1;
            }else if(mid*mid<n){
                l=mid+1;
            }else{
                return true;
            }
        }
        return false;
    }
    bool isPerfectSquare(int num) {
        return solve(num);
    }
};