class Solution {
public:
    vector<pair<int,int>>arr;
    int dp(vector<vector<int>>&requests,int index,int mask){
        if(index==requests.size()){
            for(auto j:arr){
                if(j.first!=j.second)return 0;
            }
            return __builtin_popcount(mask);
        }
        auto temp=requests[index];
        int f=temp[0];
        int s=temp[1];
        
        arr[f].second++;
        arr[s].first++;
        int a=dp(requests,index+1,mask|(1<<index));
        arr[f].second--;
        arr[s].first--;
        
        int b=dp(requests,index+1,mask);
        
        return max(a,b);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        arr.resize(n,{0,0});
        return dp(requests,0,0);
    }
};