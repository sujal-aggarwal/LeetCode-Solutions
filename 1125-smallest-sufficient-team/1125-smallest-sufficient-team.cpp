class Solution {
public:
    int n;
    int total_bits; 
    int bitmask;
    vector<int>result;
    unordered_map<string , int > dp;
    
    void solve(vector<int>&skills,int ind,int mask,vector<int>&temp){
        if(ind>=n){
            if(mask==bitmask){
                if(result.size()==0||temp.size()<result.size()){
                    result=temp;
                }
            }
            return ;
        }
        string s = to_string(ind) + to_string(mask);
        
         if(dp.find(s) != dp.end()) {
           if(dp[s] <= temp.size())
               return ; 
        }
        if(result.size()!=0&&result.size()<=temp.size())return;
        if((mask|skills[ind])!=mask){
            temp.push_back(ind);
            solve(skills,ind+1,(mask|skills[ind]),temp);
            temp.pop_back();
            dp[s] = (temp.size() != 0 ) ? temp.size() : -1;
        }
        solve(skills,ind+1,mask,temp);
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        
        n=people.size();
        total_bits=req_skills.size();
        
        unordered_map<string,int>mp;
        for(int i=0;i<total_bits;i++){
            mp[req_skills[i]]=i;
        }
        
        
        vector<int>skills;
        for(auto i:people){
            int mask=0;
            for(auto it:i){
                mask|=(1<<mp[it]);
            }
            skills.push_back(mask);
        }
        
        bitmask=(1<<total_bits)-1;
        vector<int>a;
        solve(skills,0,0,a);
        return result;
    }
};