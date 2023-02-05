class Solution {
public:
    void reverseString(string& s,int i,int j) {
        while(i<j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    string reverseWords(string s) {
        int n=s.size();
        int start=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                int last=i-1;
                reverseString(s,start,last);
                start=i+1;
            }
            else if(i==n-1)
            {
                int last=n-1;
                reverseString(s,start,last);
            }
        }
        return s;
    }
};