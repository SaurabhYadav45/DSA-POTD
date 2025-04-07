class Router {
public:
    queue<vector<int>>q;
    unordered_set<string>st;
    unordered_map<int, vector<int>>mp;
    int maxSize;
    Router(int memoryLimit) {
        maxSize = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string packet = to_string(source) + "s" + to_string(destination) + "d" + to_string(timestamp) + "t";
        if(st.find(packet) != st.end()) return false;
        if(q.size() == maxSize){
            vector<int>vec = q.front();
            int d = vec[1];
            int t = vec[2];
            q.pop();
            auto it = find(mp[d].begin(), mp[d].end(), t);
            mp[d].erase(it);
        }
        st.insert(packet);
        q.push({source, destination, timestamp});
        mp[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()){
            return {};
        }
        vector<int>vec = q.front();
        string packet = to_string(vec[0]) + "s" + to_string(vec[1]) + "d" + to_string(vec[2]) + "t";
        q.pop();
        st.erase(packet);
        int d = vec[1];
        int t = vec[2];
        auto it = find(mp[d].begin(), mp[d].end(), t);
        mp[d].erase(it);
        return vec;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int count = 0;
        for(auto& it : mp[destination]){
            if(it >= startTime && it <=endTime){
                count++;
            }
        }
        return count;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */