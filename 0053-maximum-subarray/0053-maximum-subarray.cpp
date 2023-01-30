class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_best=0;
        int best_overall=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {            
            current_best+=nums.at(i);
            if(current_best>best_overall)
                best_overall=current_best;
            if(current_best<0)
                current_best=0;
        }
        return best_overall;
    }
};