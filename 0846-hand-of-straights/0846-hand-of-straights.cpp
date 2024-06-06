#define ll long long
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupsize) {
        if(hand.size()%groupsize)return false;
        if(groupsize==1)return true;
        map<ll,ll>mp;
        for(int i:hand){
            ll j=i;
            mp[j]++;
        }
        for(auto [x,y]:mp){
            if(y==0)continue;
            for(ll i=0;i<groupsize;i++){
                if(mp[x+i]<y){
                    return false;
                }
                else{
                    mp[x+i]-=y;
                }
            }
        }
        return true;
    }
};