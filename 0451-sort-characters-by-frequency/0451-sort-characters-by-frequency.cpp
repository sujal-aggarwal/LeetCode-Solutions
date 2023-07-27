class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        unordered_map<int,vector<char>>m;
        priority_queue<int>pq;
        for(auto [i,j]:mp){
            m[j].push_back(i);
            pq.push(j);
        }
        string ans="";
        while(!pq.empty()){
            int a=pq.top();
            pq.pop();
            char ch=m[a].back();
            m[a].pop_back();
            while(a--){
                ans+=ch;
            }
        }
        return ans;
    }
};