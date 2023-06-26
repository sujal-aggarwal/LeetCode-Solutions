class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long val=0;
        int i=0,j=costs.size()-1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        while(pq.size()<candidates&&i<=j){
            pq.push({costs[i],0});i++;
        }
        int cnt=0;
        while(cnt<candidates&&i<=j){
            pq.push({costs[j],1});j--;cnt++;
        }
        while(k>0){
            auto m=pq.top();
            pq.pop();
            val+=m.first;
            if(m.second){
                if(j>=i)
                    pq.push({costs[j--],1});
            }
            else{
                if(j>=i)
                    pq.push({costs[i++],0});
            }
            k--;
        }
        return val;
    }
};