class Solution {
public:
    int n;
    int minIncrementForUnique(vector<int>& nums) {
        n=nums.size();
        int l=1e5;
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]++;
            l=min(l,i);
        }
        if(mp.size()==n)return 0;
        int cnt=0;
        while(mp.size()<n){
            if(mp.find(l)!=mp.end() && mp[l]>1){
               int a=mp[l];
                mp[l]-=(a-1);
                mp[l+1]+=(a-1);
                cnt+=(a-1);
            }
            l++;
        }
        return cnt;
    }
};