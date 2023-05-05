class Solution {
public:
    int maxVowels(string s, int k) {
        int cnt=0;
        int max_cnt=0;
        vector<char>ch={'a','e','i','o','u'};
        for(int i=0;i<k;i++){
            if(find(ch.begin(),ch.end(),s[i])!=ch.end()){
                cnt++;
            }
        }
        max_cnt=cnt;
        for(int i=k;i<s.size();i++){
            if(find(ch.begin(),ch.end(),s[i])!=ch.end()){
                cnt++;
            }
            if(find(ch.begin(),ch.end(),s[i-k])!=ch.end()){
                cnt--;
            }
            max_cnt=max(max_cnt,cnt);
        }
        return max_cnt;
    }
};