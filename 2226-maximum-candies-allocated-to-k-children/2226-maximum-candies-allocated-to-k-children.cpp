#define ll long long
class Solution {
public:
    ll n;
    int isPossible(vector<int>& candies, ll k, ll mid){
        ll count=0;
        for(int i=0;i<n;i++){
            count+=(candies[i]/mid);
        }
        return count>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        n=candies.size();
        ll minCandies=1;
        ll totalCandies=accumulate(candies.begin(),candies.end(),0LL);
        ll maxCandies=*max_element(candies.begin(),candies.end());
        if(totalCandies<k){
            return 0;
        }
        ll ans=0;
        while(minCandies<=maxCandies){
            ll midCandies=minCandies + (maxCandies-minCandies)/2;
            if(isPossible(candies,k,midCandies)){
                ans=midCandies;
                minCandies=midCandies+1;
            }else{
                maxCandies=midCandies-1;
            }
        }
        return ans;
    }
};