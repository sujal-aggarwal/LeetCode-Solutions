class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        return is_permutation(target.begin(),target.end(),arr.begin());
    }
};