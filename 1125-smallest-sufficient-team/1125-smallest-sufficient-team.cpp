// class Solution {
// public:
//     int n;
//     int total_bits;
//     int bitmask;
//     vector<int>result;
//     vector<vector<int>>dp;
    
//     void solve(vector<int>skills,int ind,int mask,vector<int>&temp){
//         if(ind>=n){
//             if(mask==bitmask){
//                 if(result.size()==0||temp.size()<result.size()){
//                     result=temp;
//                 }
//             }
//             return ;
//         }
//         if(dp[ind][mask]!=-1){
//             if(dp[ind][mask]<=temp.size())
//                 return;
//         }
//         if(result.size()!=0&&result.size()<=temp.size())return;
//         if(mask|skills[ind]!=mask){
//             temp.push_back(ind);
//             solve(skills,ind+1,(mask|skills[ind]),temp);
//             temp.pop_back();
//             dp[ind][mask]=((temp.size()!=0)?temp.size():-1);
//         }
//         solve(skills,ind+1,mask,temp);
//     }
    
//     vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        
//         n=people.size();
//         total_bits=req_skills.size();
        
//         unordered_map<string,int>mp;
//         for(int i=0;i<total_bits;i++){
//             mp[req_skills[i]]=i;
//         }
        
        
//         vector<int>skills;
//         for(int i=0;i<n;i++){
//             int mask=0;
//             for(auto it:people[i]){
//                 mask=mask|(1<<mp[it]);
//             }
//             skills.push_back(mask);
//         }
        
//         bitmask=(1<<total_bits)-1;
//         vector<int>a;
//         dp.resize(62, vector<int>(bitmask+1, -1));
//         solve(skills,0,0,a);
//         return result;
//     }
// };


class Solution {
public:
    
    int m, n;
    int target_mask;
    vector<int> result;
    unordered_map<string , int > dp;
    
    void solve(vector<int> &people_skill , int idx , vector<int> &temp, int mask ) {
        
       if(idx == people_skill.size()) {
           if(mask == target_mask) {
               if(result.size() == 0 || result.size() >= temp.size()) {
                   result = temp;
               }
           }
           return;
       }
        
        string s = to_string(idx) + to_string(mask);
        
         if(dp.find(s) != dp.end()) {
           if(dp[s] <= temp.size())
               return ; 
        }
        
        if(result.size() != 0 && temp.size() >= result.size()) 
            return; 
        
        solve(people_skill , idx + 1 , temp , mask ); // no

         if( (mask | people_skill[idx]) != mask) { //Because a person's skill set can be empty. So we won't take them
            temp.push_back(idx);
            solve(people_skill, idx + 1, temp , mask | people_skill[idx]);

            temp.pop_back();
            dp[s] = (temp.size() != 0 ) ? temp.size() : -1;
        }
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = req_skills.size();                                                                                          
        m = people.size();
        
        unordered_map<string, int> skills; //skill -> unique number
        for (int i = 0; i < n; ++i)
            skills[req_skills[i]] = i;
        
        // represent each person by a single bitmasked number (k'th bit represents if a person has the k'th skill or not)
        vector<int> people_skill;
        for (auto &v: people) {
            int skill_bit = 0;
            for (string &skill: v)
                skill_bit |= 1 << skills[skill];
            
            people_skill.push_back(skill_bit);
        }
        
        // required set of skills mask (All set to 1s)
        target_mask = pow(2, n) - 1;
        vector<int> temp;
        solve(people_skill, 0, temp, 0);
        return result;
    }
};
