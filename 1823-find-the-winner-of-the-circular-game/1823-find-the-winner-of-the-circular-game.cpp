class Solution {
public:
    int findTheWinner(int n, int k) {
        set<int>s;
        for(int i=1;i<=n;i++){
            s.insert(i);
        }
        int curr=0;
        int size=n;
        k--;
        while(true){
            if(size==1)return *s.begin();
            curr+=k;
            curr%=size;
            s.erase(next(s.begin(),curr));
            size--;
            curr%=size;
        }
        return -1;
    }
};