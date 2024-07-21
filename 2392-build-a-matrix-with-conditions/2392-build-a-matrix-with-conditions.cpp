class Solution {
public:
    vector<int> topologicalSort(int k,vector<vector<int>>& arr){
        vector<int>indegree(k+1,0);
        unordered_map<int,vector<int>>mp;
        
        for(auto vec:arr){
            indegree[vec[1]]++;
            mp[vec[0]].push_back(vec[1]);
        }
        
        queue<int>q;
        vector<int>result;
        for(int i=1;i<=k;i++){
            if(indegree[i]==0){
                q.push(i);
                result.push_back(i);
            }
        }
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            
            for(auto i:mp[curr]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                    result.push_back(i);
                }
            }
        }
        
        return (result.size()==k)?result:vector<int>();
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> row=topologicalSort(k,rowConditions);
        vector<int> col=topologicalSort(k,colConditions);
        if(row.size()==0 || col.size()==0)return {};
        vector<pair<int,int>>arr(k+1);
        for(int i=0;i<row.size();i++){
            arr[row[i]].first=i;
        }
        for(int i=0;i<col.size();i++){
            arr[col[i]].second=i;
        }
        vector result(k,vector<int>(k,0));
        for(int i=1;i<=k;i++){
            result[arr[i].first][arr[i].second]=i;
        }
        return result;
    }
};