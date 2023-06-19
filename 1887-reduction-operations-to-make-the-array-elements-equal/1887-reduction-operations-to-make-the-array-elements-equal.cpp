class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int min_element=INT_MAX;
        map<int,int,greater<int>>mp;
        for(auto i:nums){
            mp[i]++;
            min_element=min(i,min_element);
        }
        int cnt=0;
        int el=0;
        for(auto [i,j]:mp){
            if(i==min_element){
                continue;
            }
            cnt+=(j+el);
            el+=j;
        }
        return cnt;
    }
};