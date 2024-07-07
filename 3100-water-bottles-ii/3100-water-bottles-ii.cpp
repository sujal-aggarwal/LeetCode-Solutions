class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int leftBottles=0;
        int ans=0;
        while(numBottles>0){
            ans+=numBottles;
            leftBottles+=numBottles;
            numBottles=0;
            while(leftBottles>=numExchange){
                leftBottles-=numExchange;
                numBottles+=1;
                numExchange+=1;
            }
        }
        return ans;
    }
};