class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> storage(n); 
        storage[0] = 1; 
        int ans = 1; 
        for (int i = 1; i < n; i++) {
            int max = 1; 
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] < arr[i]) { 
                    int op = storage[j] + 1; 
                    if (op > max) { 
                        max = op; 
                    } 
                } 
            } 
            storage[i] = max; 
            if (max > ans) { 
                ans = max; 
            } 
        } 
        return ans;
    }
};