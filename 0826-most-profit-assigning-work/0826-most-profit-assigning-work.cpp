class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size(),m=worker.size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({difficulty[i],profit[i]});
        }
        sort(arr.begin(),arr.end());
        sort(worker.begin(),worker.end());
        int maxprofit=0;
        int j=0;
        int ans=0;
        for(int i=0;i<m;i++){
            while(j<n){
                if(arr[j].first<=worker[i]){
                    maxprofit=max(maxprofit,arr[j].second);
                    j++;
                }else{
                    break;
                }
            }
            ans+=maxprofit;
        }
        return ans;
    }
};