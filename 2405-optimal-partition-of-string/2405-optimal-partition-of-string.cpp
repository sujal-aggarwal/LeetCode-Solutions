class Solution {
public:
    int partitionString(string s) {
        int count=1,a=0;
        for(auto i:s){
            int val=i-'a';
            if(a&(1<<val)){
                a=0;
                count++;
            }
            a=a|(1<<val);
        }
        return count;
    }
};