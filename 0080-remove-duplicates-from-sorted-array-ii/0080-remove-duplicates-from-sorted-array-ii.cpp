class Solution {
public:
    vector<int>mp;
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        mp.resize((2*1e4)+1);
        int i=0,j=0;
        while(j<n){
            if(mp[nums[j]+1e4]<2){
                nums[i]=nums[j];
                mp[nums[j]+1e4]++;
                i++;j++;
            }else{
                j++;
            }
        }
        return i;
    }
};