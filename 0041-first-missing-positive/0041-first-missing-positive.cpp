class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
            This question uses a new approach 
            i.e. Negative Marking
        */
        set<int>s;
        for(auto i:nums){
            if(i>0)
                s.insert(i);
        }
        int k=1;
        for(auto i:s){
            if(i!=k)
                return k;
            k++;
        }
        if(!s.size()){
            return 1;
        }
        return k;
    }
};