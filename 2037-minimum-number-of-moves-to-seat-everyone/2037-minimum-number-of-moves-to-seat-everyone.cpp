class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int maximum=0;
        for(int i:students){
            maximum=max(maximum,i);
        }
        for(int i:seats){
            maximum=max(maximum,i);
        }
        vector<int>arr(maximum,0);
        for(int i:students){
            arr[i-1]--;
        }
        for(int i:seats){
            arr[i-1]++;
        }
        int moves=0;
        int left=0;
        for(int i:arr){
            moves+=abs(left);
            left+=i;
        }
        return moves;
    }
};