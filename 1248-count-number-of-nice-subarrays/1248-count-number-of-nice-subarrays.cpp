class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int ans=0;
        vector<int>index;
        for(int i=0;i<n;i++){
            if(nums[i]%2)index.push_back(i);
        }
        if(index.size()<k)return 0;
        int si=0;
        int ei=k-1;
        while(ei<index.size()){
            int i=index[si]-((si-1>=0)?index[si-1]+1:0);
            int j=((ei+1<index.size())?index[ei+1]:n)-index[ei]-1;
            ans+=i*j+i+j+1;
            si++;
            ei++;
        }
        return ans;
    }
};