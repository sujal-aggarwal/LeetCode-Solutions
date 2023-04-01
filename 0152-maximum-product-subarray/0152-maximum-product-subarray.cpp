class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int max_ending_here=1;
        int min_ending_here=1;
        int max_val=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<0){
                int temp=max_ending_here;
                max_ending_here=max(INT_MIN,min_ending_here*arr[i]);
                min_ending_here=min(1,temp*arr[i]);
                max_val=max(max_ending_here,max_val);
                if(max_ending_here<1){
                    max_ending_here=1;
                }
            }else if(arr[i]>0){
                max_ending_here*=arr[i];
                min_ending_here=min(1,min_ending_here*arr[i]);
                max_val=max(max_ending_here,max_val);
            }else{
                min_ending_here=1;
                max_ending_here=1;
                max_val=max(0,max_val);
            }
        }
        return max_val;
    }
};