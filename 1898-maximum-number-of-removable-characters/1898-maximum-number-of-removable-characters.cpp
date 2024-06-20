class Solution {
public:
    bool isPossible(string& s,string& p,vector<int>& removable, int k){
        unordered_map<int,int>removed;
        for(int i=0;i<k;i++){
            removed[removable[i]]++;
        }
        int i=0,j=0;
        while(i<s.length() && j<p.length()){
            if(removed.find(i)!=removed.end()){
                i++;
                continue;
            }
            if(s[i]==p[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return j>=p.length();
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l=0;
        int r=removable.size();
        int ans=0;
        while(l<=r){
            int mid=l + (r-l)/2;
            if(isPossible(s,p,removable,mid)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};