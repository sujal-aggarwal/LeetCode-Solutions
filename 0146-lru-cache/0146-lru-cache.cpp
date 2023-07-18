class LRUCache {
public:
    list<int>dll;
    unordered_map<int,pair<list<int>::iterator,int>>mp;
    int size;
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        if(mp.count(key)>0){
            auto it=mp[key];
            int val=it.second;
            dll.erase(it.first);
            dll.push_front(key);
            mp[key]={dll.begin(),val};
            return mp[key].second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)>0){
            auto it=mp[key];
            dll.erase(it.first);
            dll.push_front(key);
            mp[key]={dll.begin(),value};
        }else{
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            size--;
            if(size<0){
                int k=dll.back();
                dll.pop_back();
                mp.erase(k);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */