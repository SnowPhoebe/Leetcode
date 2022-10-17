class OrderedStream {
public:
    OrderedStream(int n) {
        index = 1;
    }
    
    vector<string> insert(int idKey, string value) {
        pq.push({idKey,value});
        vector<string> ans;
        while (!pq.empty() && pq.top().first == index) {
            ans.push_back(pq.top().second);
            pq.pop();
            ++index;
        }
        return ans;
    }
private:
    priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;
    int index;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */