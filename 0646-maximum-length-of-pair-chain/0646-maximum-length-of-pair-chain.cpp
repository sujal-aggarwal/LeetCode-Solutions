class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        auto cmp=[](vector<int>&p1,vector<int>&p2){
            return p1[1]<p2[1];
        };
        sort(pairs.begin(),pairs.end(),cmp);
        int ans=0,last=INT_MIN;
        for(auto i:pairs){
            if(i[0]>last){
                ans+=1;
                last=i[1];
            }
        }
        return ans;
    }
};