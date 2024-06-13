class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans=0;
        for_each(hours.begin(),hours.end(),[&](int current_val){
            if(current_val>=target)ans++;
        });
        return ans;
    }
};