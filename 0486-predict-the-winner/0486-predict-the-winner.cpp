class Solution {
public:
    int n;
    bool winner(vector<int>&nums,int i,int j,int sum1,int sum2,bool turn){
        if(j<i){
            return sum1>=sum2;
        }
        bool left,right;
        if(turn){
            left=winner(nums,i+1,j,sum1+nums[i],sum2,!turn);
            right=winner(nums,i,j-1,sum1+nums[j],sum2,!turn);
            return max(left,right);
        }
        left=winner(nums,i+1,j,sum1,sum2+nums[i],!turn);
        right=winner(nums,i,j-1,sum1,sum2+nums[j],!turn);
        return min(left,right);
    }
    bool PredictTheWinner(vector<int>& nums) {
        n=nums.size();
        return winner(nums,0,n-1,0,0,true);
    }
};