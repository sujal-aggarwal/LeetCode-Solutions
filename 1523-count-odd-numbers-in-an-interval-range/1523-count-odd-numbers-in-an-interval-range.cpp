class Solution {
public:
    int countOdds(int low, int high) {
        int diff=abs(low-high);
        if(diff%2==0)
        {
            if(low%2==0)
            {
                return diff/2;
            }
            else
                return (diff/2)+1;
        }
        return (diff/2)+1;
    }
};