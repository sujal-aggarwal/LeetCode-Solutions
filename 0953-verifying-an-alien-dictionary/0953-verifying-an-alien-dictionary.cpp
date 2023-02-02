class Solution {
public:
    bool isSorted(vector<string>& words,string order,int index,int*dp)
    {
        if(index==words.size()||index==words.size()-1)
            return dp[index]=true;
        if(dp[index]!=-1)
            return dp[index];
        bool ans=isSorted(words,order,index+1,dp);
        if(!ans)
            return dp[index]=false;
        for(int i=0;i<min(words[index].size(),words[index+1].size());i++)
        {
            int a=find(order.begin(),order.end(),words[index][i])-order.begin();
            int b=find(order.begin(),order.end(),words[index+1][i])-order.begin();
            if(a>b)
                return dp[index]=false;
            else if(a<b)
                return dp[index]=true;
        }
        if(words[index].size()>words[index+1].size())
            return dp[index]=false;
        return dp[index]=true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int *dp=new int[words.size()+1];
        for(int i=0;i<=words.size();i++)
            dp[i]=-1;
        return isSorted(words,order,0,dp);
    }
};