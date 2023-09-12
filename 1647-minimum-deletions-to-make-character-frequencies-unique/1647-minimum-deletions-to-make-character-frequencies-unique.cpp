class Solution {
public:
    int minDeletions(string s) {
        vector<int>arr(26,0);
        for(auto i:s){
            arr[i-'a']++;
        }
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=24;i>=0;i--){
            if (arr[i] == 0) {
                break;
            }
            if (arr[i] >= arr[i + 1]) {
                int prev = arr[i];
                arr[i] = max(0, arr[i + 1] - 1);
                ans += prev - arr[i];
            }
        }
        return ans;
    }
};