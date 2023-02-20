class Solution {
public:
    int countPrimes(int n) {
        vector<bool>seen(n,false);
        long long ans=0;
        for(long long i=2;i<n;i++){
            if(seen[i]) continue;
            ans++;
            for(long long j=i*i;j<n;j+=i){
                seen[j]=true;
            }
        }
        return ans;
    }
};