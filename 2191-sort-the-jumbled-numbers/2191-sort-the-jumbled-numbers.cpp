class Solution {
public:
    vector<int>mapping;
    int val(int nums1){
        int res1=0;
        int multiplier=1;
        if(nums1==0)res1=mapping[nums1];
        while(nums1>0){
            int digit=nums1%10;
            digit=mapping[digit];
            res1+=(multiplier*digit);
            multiplier*=10;
            nums1/=10;
        }
        return res1;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        this->mapping=mapping;
        sort(nums.begin(),nums.end(),[=](int num1,int num2){
            return val(num1)<val(num2);
        });
        return nums;
    }
};