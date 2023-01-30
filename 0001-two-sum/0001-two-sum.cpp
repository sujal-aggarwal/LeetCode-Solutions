class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>num;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            int value=target-nums[i];
            if(value==nums[i])
            {
                if(mp[nums[i]]!=i)
                {
                    num.push_back(i);
                    num.push_back(mp[nums[i]]);
                    break;
                }
            }
            else if(mp.count(value)>0)
            {
                num.push_back(i);
                num.push_back(mp[value]);
                break;
            }
        }
        return num;
    }
};