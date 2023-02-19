class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>bits(32);
        for(auto i:nums){
            for(int j=0;j<32;j++){
                int temp=i&1;
                if(temp) bits[j]++;
                i=i>>1;
            }
        }
        int ans=0;
        for(int i=0;i<32;i++){
            if(bits[i]%3)   ans=ans|(1<<i);
        }
        return ans;
    }
};