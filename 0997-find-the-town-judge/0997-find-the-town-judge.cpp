class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1)return 1;
        if(trust.size()==0)return -1;
        vector<int>count(n+1);
        int judge=0;
        int trustscore=0;
        for(int i=0;i<trust.size();i++){
            count[trust[i][1]]++;
            if(trustscore<count[trust[i][1]]){
                trustscore=count[trust[i][1]];
                judge=trust[i][1];
            }
        }
        if(trustscore<n-1)return -1;
        for(int i=0;i<trust.size();i++){
            if(trust[i][0]==judge)return -1;
        }
        return judge;
    }
};