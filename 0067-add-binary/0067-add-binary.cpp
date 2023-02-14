class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        int i=a.size()-1;
        int j=b.size()-1;
        string s="";
        while(i>=0&&j>=0)
        {
            int s1=a[i]-'0',s2=b[j]-'0';
            int sum=s1+s2+carry;
            if(sum==3)
            {
                s='1'+s;
                carry=1;
            }
            else if(sum==2)
            {
                s='0'+s;
                carry=1;
            }
            else if(sum==1)
            {
                s='1'+s;
                carry=0;
            }
            else
            {
                s='0'+s;
                carry=0;
            }
            i--;
            j--;
        }
        while(i>=0)
        {
            int sum=carry+a[i]-'0';
            if(sum==2)
            {
                carry=1;
                s='0'+s;
            }
            else if(sum==1)
            {
                carry=0;
                s='1'+s;
            }
            else {
                carry=0;
                s='0'+s;
            }
            i--;
        }
        while(j>=0)
        {
            int sum=carry+b[j]-'0';
            if(sum==2)
            {
                carry=1;
                s='0'+s;
            }
            else if(sum==1)
            {
                carry=0;
                s='1'+s;
            }
            else {
                carry=0;
                s='0'+s;
            }
            j--;
        }
        while(carry)
        {
            s='1'+s;
            carry=0;
        }
        return s;
    }
};