class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto i:words)
        {
            mp[i]++;
        }
        auto cmp = [](pair<int,string>&a,pair<int,string>&b)
        {
            if(a.first!=b.first)
            {
                return a.first<b.first;
            }
            return a.second>b.second;
        };
        priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(cmp)>pq(cmp);
        for(auto [i,j]:mp)
        {
            pq.push({j,i});
        }
        vector<string> ans;
        int i=0;
        while(!pq.empty()&&i<k)
        {
            string s=(pq.top()).second;
            pq.pop();
            ans.push_back(s);
            i++;
        }
        return ans;
    }
};