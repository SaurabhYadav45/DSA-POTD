class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        unordered_map<int, vector<int>>x_mp;
        unordered_map<int, vector<int>>y_mp;
        int min_x = INT_MAX, max_x = INT_MIN;
        int min_y = INT_MAX, max_y = INT_MIN;
        for(auto&p: coords){
            int x = p[0];
            int y = p[1];
            x_mp[x].push_back(y);
            y_mp[y].push_back(x);
            min_x = min(min_x, x);
            max_x = max(max_x, x);
            min_y = min(min_y, y);
            max_y = max(max_y, y);
        }

        long long maxArea = -1;

        for(auto& it: x_mp){
            int x = it.first;
            vector<int>&vec = it.second;
            if(vec.size() < 2) continue;
            sort(vec.begin(), vec.end());
            int base = abs(vec.back() - vec.front());

            int height = max(abs(x - min_x), abs(x - max_x));
            long long area = (long long)base*height;
            maxArea = max(maxArea, area);
        }

        for(auto& it: y_mp){
            int y = it.first;
            vector<int>&vec = it.second;
            if(vec.size() < 2) continue;
            sort(vec.begin(), vec.end());
            int base = abs(vec.back() - vec.front());

            int height = max(abs(y - min_y), abs(y - max_y));
            long long area = (long long)base*height;
            maxArea = max(maxArea, area);
        }

        if(maxArea > 0){
            return maxArea;
        } 
        return -1;
    } 
};