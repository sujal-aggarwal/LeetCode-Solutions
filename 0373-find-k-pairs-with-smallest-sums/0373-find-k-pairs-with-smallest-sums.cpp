class Solution {
public:
    typedef pair<int,int> pi;
    typedef pair<int,pi>  pii;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        int m=nums2.size();
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        vector<vector<int>>res;
        set<pi>s;
        s.insert({0,0});
        pq.push({nums1[0]+nums2[0],{0,0}});
        while(k--&&!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int i=temp.second.first;
            int j=temp.second.second;
            res.push_back({nums1[i],nums2[j]});
            if(!s.count({i,j+1})&&j+1<m){
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                s.insert({i,j+1});
            }
            if(!s.count({i+1,j})&&i+1<n){
                pq.push({nums1[i+1]+nums2[j],{i+1,j}});
                s.insert({i+1,j});
            }
        }
        return res;
    }
};