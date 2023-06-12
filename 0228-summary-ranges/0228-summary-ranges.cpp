class Solution {
public:
    void answer(vector<string>&ans,vector<pair<int,int>>&a){
        for(auto [i,j]:a){
            if(i==j){ans.push_back(to_string(i));}
            else{
                ans.push_back(to_string(i)+"->"+to_string(j));
            }
        }
    }
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string>ans;
        vector<pair<int,int>>a;
        int i=0,j=0;
        for(;j<n;j++){
            if((long long)nums[j]-nums[i]==j-i){
                if(j+1>=n){
                    a.push_back({nums[i],nums[j]});
                }
            }
            else{
                j--;
                a.push_back({nums[i],nums[j]});
                i=j+1;
            }
        }
        answer(ans,a);
        return ans;
    }
};