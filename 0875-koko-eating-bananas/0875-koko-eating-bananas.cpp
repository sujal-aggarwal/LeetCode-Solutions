class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l=0;
        long long r=*max_element(piles.begin(),piles.end());
        while(r>l+1){
            long long mid=l+(r-l)/2;
            long long time=0;
            for(auto i:piles){
                if(mid>i){
                    time++;
                }
                else{
                    time+=(i/mid);
                    if(i%mid){time++;};
                }
            }
            if(time<=h)
                r=mid;
            else
                l=mid;
        }
        return r;
    }
};