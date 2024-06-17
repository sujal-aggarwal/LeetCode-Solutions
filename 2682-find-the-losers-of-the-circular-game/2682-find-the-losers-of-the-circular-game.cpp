class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        unordered_map<int,int>mp;
        int current_friend=0;
        int count=1;
        while(mp.find(current_friend)==mp.end()){
            mp[current_friend]++;
            (current_friend+=(count*k))%=n;
            count++;
        }
        vector<int>ans;
        for(int i=1;i<=n;i++){
            if(mp.find(i-1)==mp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};