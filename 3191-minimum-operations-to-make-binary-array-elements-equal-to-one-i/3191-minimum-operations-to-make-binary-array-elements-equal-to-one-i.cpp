class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        deque<int> d;
        int ans=0;
        int flipCount=0;
        for(int i=0;i<n;i++){
            if(i>=3){
                flipCount-=d.front();
                d.pop_front();
            }
            if((nums[i]+flipCount)%2==0){
                if(i>n-3)return -1;
                ans++;
                flipCount++;
                d.push_back(1);
            }else{
                d.push_back(0);
            }
        }
        return ans;
    }
};