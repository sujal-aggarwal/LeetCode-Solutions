class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>arr(26,0);
        bool flag=true;
        for(string s:words){
            vector<int>mp(26,0);
            for(char c:s){
                mp[c-'a']++;
            }
            if(flag==true){
                arr=mp;
                flag=false;
            }else{
                for(int i=0;i<26;i++){
                    if(mp[i]<arr[i]){
                        arr[i]=mp[i];
                    }
                }
            }
        }
        vector<string>sol;
        for(int i=0;i<26;i++){
            while(arr[i]--){
                string k;
                k=char(i+'a');
                sol.push_back(k);
            }
        }
        return sol;
    }
};