class Solution {
public:
    int isPossible(vector<int>&quantities, int q,int allowed){
        int count=0;
        for(int i=0;i<quantities.size() && count<=allowed;i++){
            count+=((quantities[i]+q-1)/q);
        }
        return count<=allowed;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int minQuantity=1;
        int maxQuantity=*max_element(quantities.begin(),quantities.end());
        int ans=0;
        while(minQuantity<=maxQuantity){
            int midQuantity=minQuantity + (maxQuantity-minQuantity)/2;
            if(isPossible(quantities,midQuantity,n)){
                ans=midQuantity;
                maxQuantity=midQuantity-1;
            }else{
                minQuantity=midQuantity+1;
            }
        }
        return ans;
    }
};