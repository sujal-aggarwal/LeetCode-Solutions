class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>arr=heights;
        sort(arr.begin(),arr.end());
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(heights[i]!=arr[i]){
                count++;
            }
        }
        return count;
    }
};