class Solution {
public:
    unordered_map<string,int>mp;
    int solve(int start,int end){
        if(start>=end){
            return 1;
        }
        string key=to_string(start)+" "+to_string(end);
        if(mp.count(key))
            return mp[key];
        int ans=0;
        for(int i=start;i<=end;i++){
            int leftBst=solve(start,i-1);
            int rightBst=solve(i+1,end);
            ans+=(leftBst*rightBst);
        }
        return mp[key]=ans;
    }
    int numTrees(int n) {
        return solve(1,n);
    }
};