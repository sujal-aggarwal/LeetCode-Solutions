class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums1.size();i++){
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.rbegin(),v.rend());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=0;
        for(int i=0;i<k-1;i++){
            pq.push(v[i].second);
            sum+=v[i].second;
        }
        long long ans=0;
        for(int i=k-1;i<v.size();i++){
            sum+=v[i].second;
            ans=max(ans,sum*v[i].first);
            pq.push(v[i].second);
            sum-=(pq.top());
            pq.pop();
        }
        return ans;
    }
};