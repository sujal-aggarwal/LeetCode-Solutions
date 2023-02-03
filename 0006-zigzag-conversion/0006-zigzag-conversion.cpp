class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows>=s.size()||numRows==1)
            return s;
        string ans="";
        for(int i=0;i<numRows;i++)
        {
            if(i==0){
                int j=i;
                while(j<s.size())
                {
                    ans+=s[j];
                    j+=((numRows-1)*2);
                }
            }
            else if(i==numRows-1){
                int j=i;
                while(j<s.size())
                {
                    ans+=s[j];
                    j+=((numRows-1)*2);
                }
            }
            else{
                int j=i;
                while(j<s.size())
                {
                    ans+=s[j];
                    j+=((numRows-i-1)*2);
                    if(j<s.size())
                    {
                        ans+=s[j];
                    }
                    j+=(i*2);
                    
                }
            }
        }
        return ans;
    }
};