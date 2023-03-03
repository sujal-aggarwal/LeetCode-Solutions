class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        //Here first we aremaking every <=0 and >n element equal to n+1 cuz it will be the answer none the less
        int n = nums.size();
        for(auto &i: nums){
            if(i<=0 || i>n){
                i = n+1;
            }
        }
        
        
        //Now here we are using Negative Marking concept as we are taking each element and going to its respective index and marking -1 there by doing this we can simply check for the missing element as the only index where we wouldn't have visited
        for(auto &i: nums){
            if(abs(i)<=n){
                if(nums[abs(i)-1]>0)
                nums[abs(i)-1] = -nums[abs(i)-1];
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i]>=0)return i+1;
        }
        
        return n+1;
    }
};