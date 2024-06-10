#define ll long long
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int>arr;
        ll num=0;
        for(char c:word){
            ll i=c-'0';
            num=(((num)*(10%m))%m + (i%m))%m;
            if(num){
                arr.push_back(0);
            }else{
                arr.push_back(1);
            }
        }
        return arr;
    }
};