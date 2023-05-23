class KthLargest {
public:
    multiset<int,greater<int>>s;
    int k;
    KthLargest(int a, vector<int>& nums) {
        k=a;
        for(auto i:nums){
            s.insert(i);
        }
    }
    
    int add(int val) {
        s.insert(val);
        int cnt=1;
        for(auto i=s.begin();i!=s.end()&&cnt<=k;i++){
            if(cnt==k){
                return *i;
            }
            cnt++;
        }
        return 0;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */