class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>>directions{{1,0}, {0,1}, {-1, 0}, {0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        auto isSafe = [&](int x, int y){
            if(x < 0 || x >= m || y < 0 || y >= n){
                return false;
            }
            return true;
        };

        priority_queue<P, vector<P>, greater<P>>pq;
        vector<vector<int>>result(m, vector<int>(n, INT_MAX));
        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            int diff = pq.top().first;
            auto coordinate = pq.top().second;
            int i = coordinate.first;
            int j = coordinate.second;
            pq.pop();

            for(auto& dir : directions){
                int x = i + dir[0];
                int y = j + dir[1];
                if(isSafe(x, y)){
                    int abDiff = abs(heights[x][y] - heights[i][j]);
                    int maxDiff = max(diff, abDiff);
                    if(result[x][y] > maxDiff){
                        result[x][y] = maxDiff;
                        pq.push({maxDiff, {x,y}});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};



// class Solution {
// public:
//     typedef pair<int, pair<int, int>> P;
//     vector<vector<int>>directions{{1,0}, {0,1}, {-1, 0}, {0, -1}};
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int m = heights.size();
//         int n = heights[0].size();

//         auto isSafe = [&](int x, int y){
//             return x >= 0 && x <m && y >= 0 && y <n;
//         };

//         vector<vector<int>>result(m, vector<int>(n, INT_MAX));
//         priority_queue<P, vector<P>, greater<P>>pq;
//         pq.push({0, {0,0}});
//         result[0][0] = 0;

//         while(!pq.empty()){
//             int diff = pq.top().first;
//             auto p = pq.top().second;
//             int x = p.first;
//             int y= p.second;
//             pq.pop();

//             for(auto& dir : directions){
//                 int x_ = x + dir[0];
//                 int y_ = y + dir[1];

//                 if(isSafe(x_, y_)){
//                     int newDiff = abs(heights[x][y] - heights[x_][y_]);
//                     int maxDiff = max(diff, newDiff);
//                     if(result[x_][y_] > maxDiff){
//                         result[x_][y_] = maxDiff;
//                         pq.push({maxDiff, {x_, y_}});
//                     }
//                 }
//             }
//         }
//         return result[m-1][n-1];
//     }
// };