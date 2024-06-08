#define ll long long
class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        ll n=arr.size();
        unordered_map<ll,vector<ll>>mp;
        for(ll i=0;i<arr.size();i++){
            if(mp.find(arr[i])!=mp.end()){
                mp[arr[i]][2]++;
                mp[arr[i]][3]+=i;
            }else{
                vector<ll>temp{0,0,1,i};
                mp[arr[i]]=temp;
            }
        }
        for(auto [x,y]:mp){
            cout<<x<<endl;
            for(int i:y){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        vector<ll>ans;
        for(ll i=0;i<n;i++){
            ll val=0;
            vector<ll>& temp=mp[arr[i]];
            val+=(i*temp[1])-temp[0];
            val+=temp[3]-(i*temp[2]);
            ans.push_back(val);
            temp[1]++;temp[2]--;
            temp[0]+=i;
            temp[3]-=i;
        }
        return ans;
    }
};