class Solution {
public:
    int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        int count=0;
        int sum=0;
        while(!pq.empty()){
            if(count>right)break;
            count++;
            auto it=pq.top();
            pq.pop();
            if(count>=left && count<=right)sum=(sum+it.first%mod)%mod;
            if(it.second+1<n){
                pq.push({it.first+nums[it.second+1],it.second+1});
            }
        }
        return sum;
    }
};