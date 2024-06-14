class Solution {
public:
    int n;
    int minIncrementForUnique(vector<int>& nums) {
        n=nums.size();
        map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        if(mp.size()==n)return 0;
        int cnt=0;
        int prev=mp.begin()->first,left=mp.begin()->second-1;
        for(auto [x,y]:mp){
            int spaces=x-prev-1;
            if(spaces<0)continue;
            if(spaces>=left){
                cnt+=(left*(left+1))/2;
                left=y-1;
                prev=x;
            }else if(spaces<left){
                cnt+=(spaces*(spaces+1))/2;
                cnt+=((left-spaces)*(x-prev));
                left-=spaces;
                left+=y-1;
                prev=x;
            }
        }
        if(left){
            cnt+=(left*(left+1))/2;
        }
        return cnt;
    }
};