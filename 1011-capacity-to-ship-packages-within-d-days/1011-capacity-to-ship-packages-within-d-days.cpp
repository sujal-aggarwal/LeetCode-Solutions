class Solution {
public:
    bool isPossible(vector<int>&weights,int&days,int maxWeight){
        int count=0;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>maxWeight)
                return false;
            if(sum+weights[i]>maxWeight){count++;sum=0;}
            sum+=weights[i];
        }
        if(sum)
            count++;
        return count<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left=0,right=25000000;
        while(right>left+1){
            int mid=(left+right)/2;
            if(isPossible(weights,days,mid))
                right=mid;
            else
                left=mid;
        }
        return right;
    }
};