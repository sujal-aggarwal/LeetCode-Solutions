class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        int final=1<<n;
        vector<vector<int>>arr;
        for(int i=0;i<final;i++){
            if(__builtin_popcount(i)==k){
                vector<int>curr;
                int temp=i;
                int cnt=1;
                while(temp){
                    if(temp&1)curr.push_back(cnt);
                    cnt++;
                    temp=temp>>1;
                }
                arr.push_back(curr);
            }
        }
        return arr;
    }
};