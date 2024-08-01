class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(auto i:details){
            cnt+=(stoi(i.substr(11,2))>60);
        }
        return cnt;
    }
};