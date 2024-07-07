class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0;
        int leftBottles=0;
        while(numBottles>0){
            ans+=numBottles;
            int curr=numBottles;
            numBottles=(curr+leftBottles)/numExchange;
            leftBottles=(curr+leftBottles)%numExchange;
        }
        return ans;
    }
};