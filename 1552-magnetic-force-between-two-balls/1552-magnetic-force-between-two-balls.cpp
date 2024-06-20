class Solution {
public:
    int n;
    int isPossible(vector<int>&position , int m, int force){
        int prev=position[0];
        int count=1;
        for(int i=1;i<n;i++){
            int curr=position[i];
            if(curr-prev>=force){
                prev=curr;
                count++;
            }
        }
        return count>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        n=position.size();
        sort(position.begin(),position.end());
        int minForce=1;
        int maxForce=(position[n-1]-position[0])/(m-1);
        int ans=0;
        while(minForce<=maxForce){
            int midForce=minForce + (maxForce-minForce)/2;
            if(isPossible(position,m,midForce)){
                ans=midForce;
                minForce=midForce+1;
            }else{
                maxForce=midForce-1;
            }
        }
        return ans;
    }
};