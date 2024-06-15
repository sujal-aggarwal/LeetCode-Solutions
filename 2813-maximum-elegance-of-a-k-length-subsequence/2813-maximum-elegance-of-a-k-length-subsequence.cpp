#define ll long long
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        int n=items.size();
        unordered_map<ll,ll>mp;
        ll ans=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        sort(items.begin(),items.end(),greater<vector<int>>());
        for(int i=0;i<k;i++){
            mp[items[i][1]]++;
            ans+=items[i][0];
            pq.push(items[i]);
        }
        
        ll m=mp.size();
        ans+=(m*m);
        ll curr=ans;
        for(int i=k;i<n;i++){
            if(mp[items[i][1]]>=1)continue;
            
            while(!pq.empty() && mp[pq.top()[1]]==1)pq.pop();
            
            if(pq.empty())break;
            
            auto p=pq.top();
            pq.pop();
            curr-=p[0];
            curr-=(m*m);
            
            curr+=items[i][0];
            m++;
            curr+=(m*m);
            
            mp[p[1]]--;
            mp[items[i][1]]++;
            // pq.push(items[i]);
            
            ans=max(curr,ans);
        }
        return ans;
    }
};