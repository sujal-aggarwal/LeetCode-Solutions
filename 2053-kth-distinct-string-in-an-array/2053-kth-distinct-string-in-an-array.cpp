class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mp;
        for(string s:arr){
            mp[s]++;
        }
        int count=0;
        string s="";
        for(auto i:arr){
            if(mp[i]==1)count++;
            if(count==k){
                s=i;
                break;
            }
        }
        return s;
    }
};