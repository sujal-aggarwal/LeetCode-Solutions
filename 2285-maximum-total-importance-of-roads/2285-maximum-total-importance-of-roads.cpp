class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int m=roads.size();
        map<int,int,greater<int>>mp;
        for(int i=0;i<m;i++){
            int a=roads[i][0];
            int b=roads[i][1];
            mp[a]++;mp[b]++;
        }
        priority_queue<int>pq;
        for(auto [i,j]:mp){
            pq.push(j);
        }
        long long ans=0;
        long long cnt=n;
        while(!pq.empty()){
            ans+=(pq.top()*cnt--);
            pq.pop();
        }
        return ans;
    }
};