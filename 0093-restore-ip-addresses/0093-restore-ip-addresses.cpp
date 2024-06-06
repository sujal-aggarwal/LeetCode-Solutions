class Solution {
public:
    vector<string>ans;
    void restore(string s, int i,string ip){
        if(s.size()==0 && i==0){
            if(ip.back()=='.'){
                ip.pop_back();
            }
            ans.push_back(ip);
            return;
        }
        if(s.size() && i<=0){
            return;
        }
        if(s.size()==0)return;
        restore(s.substr(1),i-1,ip+s[0]+'.');
        if(s[0]!='0'){
            int k=0;
            if(s.size()>1){
                k=stoi(s.substr(0,2));
                if(k>=0 && k<=255){
                    restore(s.substr(2),i-1,ip+s.substr(0,2)+'.');
                }
            }
            if(s.size()>2){
                k=stoi(s.substr(0,3));
                if(k>=0 && k<=255){
                    restore(s.substr(3),i-1,ip+s.substr(0,3)+'.');
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string k="";
        restore(s,4,k);
        return ans;
    }
};