class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(trainers.rbegin(),trainers.rend());
        sort(players.rbegin(),players.rend());
        int n=players.size(),m=trainers.size();
        int i=0,j=0;
        int ans=0;
        while(i<n && j<m){
            if(players[i]>trainers[j]){
                i++;
            }else{
                ans++;
                i++;
                j++;
            }
        }
        return ans;
    }
};