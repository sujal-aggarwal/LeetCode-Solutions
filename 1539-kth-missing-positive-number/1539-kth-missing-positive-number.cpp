class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int val=1;
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=val){
                cnt++;
                i--;
                if(cnt==k){
                    return val;
                }
                val++;
            }else{
                val++;
            }
        }
        cnt++;
        while(cnt<k){
            cnt++;
            val++;
        }
        return val;
    }
};