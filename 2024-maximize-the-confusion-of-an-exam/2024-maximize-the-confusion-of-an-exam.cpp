class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        int i=0,j=0,ans=0;
        int f=0;
        int t=0;
        while(j<n){
            if(answerKey[j]=='T')t++;
            if(answerKey[j]=='F')f++;
            if(min(t,f)>k){
                while(min(t,f)>k){
                    if(answerKey[i]=='T')t--;
                    if(answerKey[i]=='F')f--;
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};