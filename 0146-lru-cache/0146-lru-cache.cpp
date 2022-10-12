class LRUCache {
public:
    LRUCache(int capacity) {
        size = 0;
        _capacity = capacity;
    }
    
    int get(int key) {
        // auto it = hash_table.find(key);
        // if (it != hash_table.end()) {
        //     lst.splice(lst.begin(), lst, it->second);
        //     return it->second->second;
        // }
        // return -1;
        auto it = hash_table.find(key);
        if (it == hash_table.end()) return -1;
        else {
            lst.splice(lst.begin(), lst, it->second);
            return it->second->second;
        }
    }
    
    void put(int key, int value) {
        auto it = hash_table.find(key);
        if (it != hash_table.end()) {
            it->second->second = value;
            lst.splice(lst.begin(), lst, it->second);
        }
        else if (size < _capacity) {
            lst.push_front({key,value});
            hash_table[key] = lst.begin();
            ++size;
        }
        else if (size == _capacity){
            hash_table.erase(lst.back().first);
            lst.pop_back();
            lst.push_front({key,value});
            hash_table[key] = lst.begin();
        }
        // auto it = hash_table.find(key);
        // if (it != hash_table.end()) {
        //     lst.splice(lst.begin(), lst, it->second);
        //     it->second->second = value;
        // }
        // else {
        //     if (size < _capacity) {
        //         lst.push_front({key,value});
        //         hash_table[key] = lst.begin();
        //         ++size;
        //     }
        //     else if (size == _capacity) {
        //         hash_table.erase(lst.back().first);
        //         lst.pop_back();
        //         lst.push_front({key,value});
        //         hash_table[key] = lst.begin();
        //     }
        // }
    }
    
private:
    int _capacity;
    int size;
    unordered_map<int,list<pair<int,int>>::iterator> hash_table;
    list<pair<int,int>> lst;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */