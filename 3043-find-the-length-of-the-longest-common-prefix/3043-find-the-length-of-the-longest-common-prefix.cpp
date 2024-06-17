class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        for(int i:arr1){
            int curr=i;
            while(curr){
                mp[curr]++;
                curr/=10;
            }
        }
        int ans=0;
        for(int i:arr2){
            int curr=i;
            while(curr){
                if(mp.find(curr)!=mp.end()){
                    ans=max(ans,(int)(log10(curr))+1);
                }
                curr/=10;
            }
        }
        return ans;
    }
};