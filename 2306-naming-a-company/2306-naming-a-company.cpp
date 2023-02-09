class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> arr[26];
        for(auto i:ideas)
        {
            arr[i[0]-'a'].insert(i.substr(1));
        }
        long long ans=0;
        for(int i=0;i<25;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                int same=0;
                for(auto suffix:arr[i])
                {
                    if(arr[j].count(suffix))
                    {
                        same++;
                    }
                }
                ans+=2LL*(arr[j].size()-same)*(arr[i].size()-same);
            }
        }
        return ans;
    }
};