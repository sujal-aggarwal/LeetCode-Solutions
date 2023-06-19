class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int height=0;
        int curr=0;
        for(auto i:gain){
            curr+=i;
            height=max(height,curr);
        }
        return height;
    }
};