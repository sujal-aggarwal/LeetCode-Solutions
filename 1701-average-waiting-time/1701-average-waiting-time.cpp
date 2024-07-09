class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        double ans=0;
        int chefTime=0;
        for(auto vec:customers){
            int startTime=vec[0];
            int endTime=vec[1];
            if(chefTime>=startTime){
                chefTime+=endTime;
                ans+=(chefTime-startTime);
            }else{
                chefTime=startTime+endTime;
                ans+=(chefTime-startTime);
            }
        }
        return ans/n;
    }
};