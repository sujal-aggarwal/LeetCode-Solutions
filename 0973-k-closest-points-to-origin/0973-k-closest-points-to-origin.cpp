class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       map<int,vector<pair<int,int>>>mp;
        for(auto i:points){
            int distance=(i[0]*i[0])+(i[1]*i[1]);
            mp[distance].push_back({i[0],i[1]});   
        }
        vector<vector<int>>pairs;
        for(auto i:mp){
            vector<pair<int,int>> arr=i.second;
            for(auto j:arr){
                if(pairs.size()>=k){
                    break;
                }
                vector<int>a;
                a.push_back(j.first);
                a.push_back(j.second);
                pairs.push_back(a);
                if(pairs.size()>=k){
                    break;
                }
            }
            if(pairs.size()>k){
                break;
            }
        }
        return pairs;
    }
};