class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str2.size()<str1.size())
            swap(str2,str1);
        int m=str1.size();
        int n=str2.size();
        for(int k=m;k>0;k--)
        {
            if(n%k!=0)continue;
            if(m%k!=0)continue;
            string ans=str1.substr(0,k);
            string test=ans;
            int a=m/k;
            for(int i=1;i<a;i++)
                test+=ans;
            if(str1!=test)
                continue;
            test=ans;
            a=n/k;
            for(int i=1;i<a;i++)
                test+=ans;
            if(str2!=test)
                continue;
            return ans;
        }
        return "";
    }
};