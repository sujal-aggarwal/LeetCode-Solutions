class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char>q;
        int rcnt=0,dcnt=0,rban=0,dban=0;
        for(auto i:senate){
            q.push(i);
            if(i=='R'){rcnt++;}
            else{dcnt++;}
        }
        while(rcnt&&dcnt){
            int curr=q.front();
            q.pop();
            if(curr=='R'){
                if(rban){
                    rban--;
                    rcnt--;
                }else{
                    dban++;
                    q.push('R');
                }
            }else{
                if(dban){
                    dban--;
                    dcnt--;
                }else{
                    rban++;
                    q.push('D');
                }
            }
        }
        return (q.front()=='R')?"Radiant":"Dire";
    }
};