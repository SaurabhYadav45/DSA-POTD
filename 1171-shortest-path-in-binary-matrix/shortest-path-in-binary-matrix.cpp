class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>>directions{{0,1}, {1, 0}, {0,-1}, {-1, 0}, {1, 1},{-1,-1}, {1, -1}, {-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int  m = grid.size();
        int n = grid[0].size();

        if(m == 0 || n == 0 || grid[0][0] != 0)
            return -1;

        auto isSafe = [&](int x, int y){
            if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 1){
                return false;
            }
            return true;
        };

        priority_queue<P, vector<P>, greater<P>>pq;
        vector<vector<int>>result(m, vector<int>(n, INT_MAX));
        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            int d = pq.top().first;
            auto coordinates = pq.top().second;
            int i = coordinates.first;
            int j = coordinates.second;
            pq.pop();

            for(auto& dir : directions){
                int x = i + dir[0];
                int y = j + dir[1];
                int dist = 1;
                if(isSafe(x, y) && d+dist < result[x][y]){
                    pq.push({d+dist, {x,y}});
                    grid[x][y] = 1;
                    result[x][y] = d+dist;
                }
            }
        }

        if(result[m-1][n-1] == INT_MAX) return -1;

        return result[m-1][n-1] + 1;
    }
};




// class Solution {
// public:
//     typedef pair<int, pair<int,int>> P;
//     vector<vector<int>>directions{{1,1}, {-1,-1}, {0,1}, {1,0}, {-1, 0}, {0,-1}, {1,-1}, {-1, 1}};
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         priority_queue<P, vector<P>, greater<P>>pq;
//         vector<vector<int>>result(m, vector<int>(n, INT_MAX));

//         if(m == 0 || n == 0|| grid[0][0] != 0){
//             return -1;
//         }

//         auto isSafe = [&](int&x, int&y){
//             return x >=0 && x <m && y >=0 && y<n ;
//         };

//         result[0][0] = 0;
//         pq.push({0, {0,0}});
//         while(!pq.empty()){
//             int d = pq.top().first;
//             pair<int, int>adjNode = pq.top().second;
//             int x = adjNode.first;
//             int y = adjNode.second;
//             pq.pop();

//             for(auto& dir : directions){
//                 int x_ = x + dir[0];
//                 int y_ = y + dir[1];

//                 int dist = 1;
//                 if(isSafe(x_, y_) && grid[x_][y_] == 0 && d + dist < result[x_][y_]){
//                     pq.push({d + dist, {x_, y_}});
//                     grid[x_][y_] = 1;
//                     result[x_][y_] = d + dist;
//                 }
//             }
//         }
//         if(result[m-1][n-1] == INT_MAX){
//             return -1;
//         }

//         return result[m-1][n-1] +1;
//     }
// };