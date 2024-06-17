class ProductOfNumbers {
public:
    vector<int>prefix;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0){
            prefix.clear();
            return;
        }
        if(prefix.size()==0){
            prefix.push_back(num);
        }else{
            int a=prefix[prefix.size()-1];
            prefix.push_back(a*num);
        }
    }
    
    int getProduct(int k) {
        if(prefix.size()<k)return 0;
        int n=prefix.size();
        if(k==n)return prefix[n-1];
        return prefix[n-1]/prefix[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */