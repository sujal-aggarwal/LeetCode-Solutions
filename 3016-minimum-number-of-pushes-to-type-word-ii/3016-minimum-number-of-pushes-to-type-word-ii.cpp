class Solution {
public:
    #define pic pair<int,char>
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(auto s:word){
            mp[s]++;
        }
        if(mp.size()<=8)return word.size();
        priority_queue<pic>pq;
        for(auto [i,j]:mp){
            pq.push({j,i});
        }
        int count=0;
        int ans=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            count++;
            ans+=(((count+7)/8)*(it.first));
        }
        return ans;
    }
};