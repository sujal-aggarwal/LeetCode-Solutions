class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int count = accumulate(nums.begin(), nums.end(), 0);
        if (count == 0 || count == n) return 0;
        int count_0 = 0;
        int ans = INT_MAX;
        for (int j = 0; j < count; j++) {
            if (nums[j] == 0) count_0++;
        }
        ans = count_0;
        for (int i = 1; i < n; i++) {
            if (nums[(i - 1) % n] == 0) count_0--;
            if (nums[(i + count - 1) % n] == 0) count_0++;
            ans = min(ans, count_0);
        }
        return ans;
    }
};
