class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        // unordered_map<int, vector<int>>x_mp;
        // unordered_map<int, vector<int>>y_mp;
        // int min_x = INT_MAX, max_x = INT_MIN;
        // int min_y = INT_MAX, max_y = INT_MIN;
        // for(auto&p: coords){
        //     int x = p[0];
        //     int y = p[1];
        //     x_mp[x].push_back(y);
        //     y_mp[y].push_back(x);
        //     min_x = min(min_x, x);
        //     max_x = max(max_x, x);
        //     min_y = min(min_y, y);
        //     max_y = max(max_y, y);
        // }

        // long long maxArea = -1;

        // for(auto& it: x_mp){
        //     int x = it.first;
        //     vector<int>&vec = it.second;
        //     if(vec.size() < 2) continue;
        //     sort(vec.begin(), vec.end());
        //     int base = abs(vec.back() - vec.front());

        //     int height = max(abs(x - min_x), abs(x - max_x));
        //     long long area = (long long)base*height;
        //     maxArea = max(maxArea, area);
        // }

        // for(auto& it: y_mp){
        //     int y = it.first;
        //     vector<int>&vec = it.second;
        //     if(vec.size() < 2) continue;
        //     sort(vec.begin(), vec.end());
        //     int base = abs(vec.back() - vec.front());

        //     int height = max(abs(y - min_y), abs(y - max_y));
        //     long long area = (long long)base*height;
        //     maxArea = max(maxArea, area);
        // }

        // if(maxArea > 0){
        //     return maxArea;
        // } 
        // return -1;



        unordered_map<int, pair<int, int>> x_map; // x -> (minY, maxY)
        unordered_map<int, pair<int, int>> y_map; // y -> (minX, maxX)
        int global_min_x = INT_MAX, global_max_x = INT_MIN;
        int global_min_y = INT_MAX, global_max_y = INT_MIN;

        for (auto& p : coords) {
            int x = p[0], y = p[1];

            // Update x_map for vertical segment
            if (x_map.count(x)) {
                x_map[x].first = min(x_map[x].first, y);
                x_map[x].second = max(x_map[x].second, y);
            } else {
                x_map[x] = {y, y};
            }

            // Update y_map for horizontal segment
            if (y_map.count(y)) {
                y_map[y].first = min(y_map[y].first, x);
                y_map[y].second = max(y_map[y].second, x);
            } else {
                y_map[y] = {x, x};
            }

            // Global min/max x and y
            global_min_x = min(global_min_x, x);
            global_max_x = max(global_max_x, x);
            global_min_y = min(global_min_y, y);
            global_max_y = max(global_max_y, y);
        }

        long long max_area = -1;

        // Vertical segments (same x)
        for (auto& [x, y_range] : x_map) {
            int base = y_range.second - y_range.first;
            if (base == 0) continue; // No vertical base

            int height = max(abs(x - global_min_x), abs(x - global_max_x));
            if (height == 0) continue; // no third point away from line

            max_area = max(max_area, 1LL * base * height);
        }

        // Horizontal segments (same y)
        for (auto& [y, x_range] : y_map) {
            int base = x_range.second - x_range.first;
            if (base == 0) continue; // No horizontal base

            int height = max(abs(y - global_min_y), abs(y - global_max_y));
            if (height == 0) continue; // no third point away from line

            max_area = max(max_area, 1LL * base * height);
        }

        return max_area > 0 ? max_area : -1;
    } 
};