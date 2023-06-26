class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long val=0;
        int i=0,j=costs.size()-1;
        priority_queue<int,vector<int>,greater<int>>pq1,pq2;
        while(k>0){
            while(pq1.size()<candidates&&i<=j){
                pq1.push(costs[i]);i++;
            }
            while(pq2.size()<candidates&&i<=j){
                pq2.push(costs[j]);j--;
            }
            int min1=((pq1.empty())?INT_MAX:pq1.top());
            int min2=((pq2.empty())?INT_MAX:pq2.top());
            if(min1<=min2){
                val+=min1;
                pq1.pop();
            }else{
                val+=min2;
                pq2.pop();
            }
            k--;
        }
        return val;
    }
};