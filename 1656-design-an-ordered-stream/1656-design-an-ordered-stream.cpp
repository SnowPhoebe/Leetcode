class OrderedStream {
public:
    OrderedStream(int n) {
        vec.resize(n+1,"A");
        index = 1;
    }
    
    vector<string> insert(int idKey, string value) {
        vec[idKey] = value;
        vector<string> ans;
        while (index < vec.size() && vec[index] != "A") {
            ans.push_back(vec[index]);
            ++index;
        }
        return ans;
    }
private:
    vector<string> vec;
    int index;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */