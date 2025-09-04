class LRUCache {
public:
    list<int>dll;
    unordered_map<int, pair<list<int>::iterator,int>>mp;
    int size;
    LRUCache(int capacity) {
        size = capacity;
    }

    void makeRecentlyUsed(int key){
        auto address = mp[key].first;
        dll.erase(address);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        makeRecentlyUsed(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            makeRecentlyUsed(key);
        }
        else{
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            size--;
        }

        if(size < 0){
            int LRU = dll.back();
            mp.erase(LRU);
            dll.pop_back();
            size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */