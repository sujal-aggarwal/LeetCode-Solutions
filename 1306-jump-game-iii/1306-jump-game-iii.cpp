class Solution {
public:
    int INF=1e9+7;
    bool canReach(vector<int>& arr, int start) {
        if(start>=arr.size()||start<0)
            return false;
        if(arr[start]==0)
            return true;
        int val=arr[start];
        arr[start]=INF;
        return canReach(arr,start-val)||canReach(arr,start+val);
    }
};