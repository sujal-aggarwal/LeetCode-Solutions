class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        for(string s:words){
            mp[s]++;
        }
        int ans=0;
        int oddfreq=0;
        for(string s:words){
            string k=s;
            reverse(k.begin(),k.end());
            if(k==s){
                int i=mp[k];
                if(i%2==0){
                    ans+=(i/2)*4;
                }else{
                    ans+=(i/2)*4;
                    oddfreq=1;
                }
                mp[k]=0;
            }else{
                int i=min(mp[k],mp[s]);
                ans+=i*4;
                mp[k]-=i;
                mp[s]-=i;
            }
        }
        return oddfreq?ans+2:ans;
    }
};