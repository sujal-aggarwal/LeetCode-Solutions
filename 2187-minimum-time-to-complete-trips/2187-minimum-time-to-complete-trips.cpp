class Solution {
public:
    bool works(long long given_time,vector<int>&time,int& totalTrips){
        long long trips=0;
        for(auto i:time){
            trips+=given_time/i;
            if(trips>=totalTrips){
                return true;
            }
        }
        return trips>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=0;
        long long r=*max_element(time.begin(),time.end());
        r*=totalTrips;
        while(r>l+1){
            long long mid=l+(r-l)/2;
            if(works(mid,time,totalTrips)){
                r=mid;
            }else{
                l=mid;
            }
        }
        return r;
    }
};