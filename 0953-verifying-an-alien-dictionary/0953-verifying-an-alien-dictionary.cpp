class Solution {
public:
    bool isSorted(vector<string>& words,string order,int index)
    {
        if(index==words.size()||index==words.size()-1)
            return true;
        bool ans=isSorted(words,order,index+1);
        if(!ans)
            return false;
        for(int i=0;i<min(words[index].size(),words[index+1].size());i++)
        {
            int a=find(order.begin(),order.end(),words[index][i])-order.begin();
            int b=find(order.begin(),order.end(),words[index+1][i])-order.begin();
            if(a>b)
                return false;
            else if(a<b)
                return true;
        }
        if(words[index].size()>words[index+1].size())
            return false;
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        return isSorted(words,order,0);
    }
};