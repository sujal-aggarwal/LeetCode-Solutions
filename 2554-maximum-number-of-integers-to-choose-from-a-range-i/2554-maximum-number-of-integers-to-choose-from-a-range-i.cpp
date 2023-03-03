class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int>ans(n,1);
        for(int i=0;i<banned.size();i++){
            if(banned[i]<=n && ans[banned[i]-1]>0){
                ans[banned[i]-1]*=-1;
            }
        }
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(ans[i]>0&&i+1+sum<=maxSum){
                sum+=(i+1);
                count++;
            }
            else if(i+1+sum>maxSum){
                break;
            }
        }
        return count;
    }
};