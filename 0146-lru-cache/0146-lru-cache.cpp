class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        auto it = hash_table.find(key);
        if (it == hash_table.end()) return -1;
        else {
            lru_list.splice(lru_list.begin(), lru_list, it->second);
            return it->second->second;
        }
    }
    
    void put(int key, int value) {
        auto it = hash_table.find(key);
        if (it != hash_table.end()) {
            it->second->second = value;
            lru_list.splice(lru_list.begin(), lru_list, it->second);
        }
        else if (size < _capacity) {
            lru_list.push_front({key,value});
            hash_table[key] = lru_list.begin();
            ++size;
        }
        else if (size == _capacity){
            hash_table.erase(lru_list.back().first);
            lru_list.pop_back();
            lru_list.push_front({key,value});
            hash_table[key] = lru_list.begin();
        }
    }
private:
    int _capacity;
    int size;
    unordered_map<int,list<pair<int,int>>::iterator> hash_table;
    list<pair<int,int>> lru_list;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */