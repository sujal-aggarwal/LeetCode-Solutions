class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prev=0;
        unordered_map<int,int>mp;
        for_each(nums.begin(),nums.end(),[&](int& current_value){
            current_value+=prev;
            current_value%=k;
            current_value+=k;
            current_value%=k;
            mp[current_value]++;
            prev=current_value;
        });
        int count=0;
        for(int i:nums){
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto& [x,y]:mp){
            if(y>1)
                count+=((y*(y-1))/2);
            if(x==0){
                count+=y;
                continue;
            }
        }
        return count;
    }
};