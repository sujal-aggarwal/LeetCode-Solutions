class Solution {
public:
    int maxSatisfaction(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int sum=0,max_sum=0,i=arr.size()-1;
        while(sum>=0&&i>=0){
            sum+=arr[i];
            if(sum<0){
                break;
            }
            max_sum+=sum;
            i--;
        }
        return max_sum;
    }
};