class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int>arr,ans;
        for(auto i:obstacles){
            int index=upper_bound(arr.begin(),arr.end(),i)-arr.begin();
            if(index==arr.size()){
                ans.push_back(arr.size()+1);
                arr.push_back(i);
            }else{
                ans.push_back(index+1);
                arr[index]=i;
            }
        }
        return ans;
    }
};