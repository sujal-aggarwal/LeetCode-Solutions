class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>pq;
        int min_value=INT_MAX;
        for(auto&i:nums){
            if(i%2!=0){
                i*=2;
            }
            pq.push(i);
            min_value=min(min_value,i);
        }
        int ans=INT_MAX;
        while(true){
            int max_value=pq.top();
            pq.pop();
            ans=min(ans,max_value-min_value);
            if(max_value%2){
                break;
            }
            max_value/=2;
            pq.push(max_value);
            min_value=min(min_value,max_value);
        }
        return ans;
    }
};