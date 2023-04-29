class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){return 0;}
        sort(nums.begin(),nums.end());
        int length=1,max_length=1;
        int prev=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==prev+1){
                prev=nums[i];
                length++;
                max_length=max(max_length,length);
            }else if(prev==nums[i]){
                continue;
            }else{
                prev=nums[i];
                length=1;
                max_length=max(max_length,length);
            }
        }
        return max_length;
    }
};