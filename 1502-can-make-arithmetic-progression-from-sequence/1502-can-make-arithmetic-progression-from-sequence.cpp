class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if(arr.size()==2)return true;
        unordered_map<int,int>mp;
        int min_element=INT_MAX;
        int max_element=INT_MIN;
        int dflag=0;
        for(auto i:arr){
            mp[i]++;
            if(mp[i]>1){
                dflag=1;
            }
            min_element=min(min_element,i);
            max_element=max(max_element,i);
        }
        if(max_element==min_element)return true;
        if(dflag==1)return false;
        int diff=max_element-min_element;
        if(diff%(arr.size()-1)!=0)return false;
        diff/=(arr.size()-1);
        while(min_element<max_element){
            if(mp[min_element]<=0)return false;
            min_element+=diff;
        }
        if(min_element!=max_element)return false;
        return true;
    }
};