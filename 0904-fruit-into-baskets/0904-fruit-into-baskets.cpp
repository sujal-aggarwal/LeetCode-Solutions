class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        set<int>s;
        int i=0;
        int j=1;
        int maxsize=1;
        map<int,int>mp;
        mp[fruits[i]]++;
        s.insert(fruits[i]);
        while(j<fruits.size())
        {
            s.insert(fruits[j]);
            mp[fruits[j]]++;
            if(s.size()>2)
            {
                maxsize=max(maxsize,j-i);
                while(s.size()!=2)
                {
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0)
                        s.erase(fruits[i]);
                    i++;
                }
            }
            j++;
        }
        maxsize=max(maxsize,j-i);
        return maxsize;
    }
};