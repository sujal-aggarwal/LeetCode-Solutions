class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>a;
    map<pair<string,string>,vector<int>>mp;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        a[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        mp[{a[id].first,stationName}].push_back(t-a[id].second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        int div=0;
        double sum=0;
        for(auto i:mp[{startStation,endStation}]){
            sum+=i;
            div++;
        }
        return sum/div;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */