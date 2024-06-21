class Solution {
public:
    int n;
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        n=customers.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(i<minutes){
                ans+=customers[i];
            }else{
                ans+=(grumpy[i]==0)?customers[i]:0;                
            }
        }
        int si=1,ei=minutes;
        int temp=ans;
        while(ei<n){
            if(grumpy[ei]){
                temp+=customers[ei];
            }
            if(grumpy[si-1]){
                temp-=customers[si-1];
            }
            ans=max(ans,temp);
            ei++;
            si++;
        }
        return ans;
    }
};