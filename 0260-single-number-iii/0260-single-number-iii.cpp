class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long a=0;
        for(auto i:nums){
            a^=i;
        }
        a=a&(-1*a);
        int first=0;
        int second=0;
        for(auto i:nums){
            if(i&a)
                first^=i;
            else
                second^=i;
        }
        vector<int>arr;
        arr.push_back(first);        
        arr.push_back(second);
        return arr;
    }
};