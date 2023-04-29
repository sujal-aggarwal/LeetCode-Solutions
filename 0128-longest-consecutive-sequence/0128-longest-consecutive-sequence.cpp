class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){return 0;}
        unordered_set<int>s;
        for(auto i:nums){
            s.insert(i);
        }
        int max_streak=1;
        for(auto i:s){
            if(!s.count(i-1)){
                int currNum=i;
                int currentStreak=1;
                while(s.count(currNum+1)){
                    currentStreak++;
                    currNum++;
                }
                max_streak=max(max_streak,currentStreak);
            }
        }
        return max_streak;
    }
};