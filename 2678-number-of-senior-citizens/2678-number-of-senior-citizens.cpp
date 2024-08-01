class Solution {
public:
    int countSeniors(vector<string>& details) {
        return accumulate(details.begin(),details.end(),0,[](int sum,string i){
            return sum + (stoi(i.substr(11,2))>60); 
        });
    }
};