class Solution {
public:
    int n;
    bool isTrue(int x,int y,int z){
        return (x&1 && y&1 && z&1);
    }
    bool threeConsecutiveOdds(vector<int>& arr) {
        n=arr.size();
        if(n<3)return false;
        for(int i=0;i<n-2;i++){
            if(isTrue(arr[i],arr[i+1],arr[i+2]))return true;
        }
        return false;
    }
};