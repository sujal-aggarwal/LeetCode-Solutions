/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=1,r=n;
        int ans=-1;
        while(r>=l){
            int mid=l+(r-l)/2;
            int a=guess(mid);
            if(a==0){
                ans=mid;
                break;
            }
            else if(a==-1)r=mid-1;
            else if(a==1)l=mid+1;
        }
        return ans;
    }
};