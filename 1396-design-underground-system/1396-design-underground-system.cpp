class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        check_in[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        if (check_in.find(id) == check_in.end()) return;
        string name = check_in[id].first;
        int start_time = check_in[id].second;
        name += "-"+stationName;
        total_time[name].first += t-start_time;
        ++total_time[name].second;
        check_in.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string name = startStation + "-" + endStation;
        auto &pair = total_time[name];
        return ((double)pair.first/pair.second);
    }
private:
    unordered_map<int,pair<string,int>> check_in;
    unordered_map<string, pair<int,int>> total_time;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */