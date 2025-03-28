class Solution {
public:
    int m, n;
    vector<vector<int>>directions{{0,1}, {0,-1}, {1, 0}, {-1, 0}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        m = grid.size();
        n = grid[0].size();

        int Q = queries.size();
        vector<int>result(Q);

        vector<pair<int, int>>sortedQ;

        for(int i=0; i<Q; i++){
           int query = queries[i];
           sortedQ.push_back({query, i});
        }

        sort(sortedQ.begin(), sortedQ.end());

        vector<vector<bool>>visited(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>>pq;

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        int points = 0;

        for(int i=0; i<Q; i++){
            int queryVal = sortedQ[i].first;
            int queryIdx = sortedQ[i].second;
            while(!pq.empty() && pq.top()[0] < queryVal){
                int val = pq.top()[0];
                int i = pq.top()[1];
                int j = pq.top()[2];
                pq.pop();

                points++;

                for(auto& dir : directions){
                    int x = i + dir[0];
                    int y = j + dir[1];

                    if( x >=0 && x < m && y >= 0 && y <n && !visited[x][y]){
                        pq.push({grid[x][y], x, y});
                        visited[x][y] =true;
                    }
                }
            }
            result[queryIdx] = points;
        }
        return result;
    }
};








//                        *************** Brute Force ************
//                              ********** DFS *****************

// class Solution {
// public:
//     int m, n;
//     vector<vector<int>>directions{{0,1}, {0,-1}, {1, 0}, {-1, 0}};
//     int dfs(int i, int j, vector<vector<int>>& grid, int query, vector<vector<bool>>&visited){
//         if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == true || grid[i][j] >= query){
//             return 0;
//         }

//         int points = 1;
//         visited[i][j] = true;
        
//         for(auto& dir : directions){
//             int x = i + dir[0];
//             int y = j + dir[1];

//             points += dfs(x, y, grid, query, visited);
//         }
//         return points;
//     }
//     vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
//         m = grid.size();
//         n = grid[0].size();

//         vector<int>result;

//         for(int& query : queries){
//             vector<vector<bool>>visited(m, vector<bool>(n, false));
//             int points = dfs(0, 0, grid, query, visited);
//             result.push_back(points);
//         }
//         return result;
//     }
// };



//                             ********** BFS *************

// class Solution {
// public:
//     int m, n;
//     vector<vector<int>>directions{{0,1}, {0,-1}, {1, 0}, {-1, 0}};
//     int bfs(vector<vector<int>>& grid, int query){
//         queue<pair<int, int>>q;
//         vector<vector<bool>>visited(m, vector<bool>(n, false));
//         int points = 0;

//         q.push({0, 0});
//         visited[0][0] = true;

//         while(!q.empty()){
//             int N = q.size();
//             while(N--){
//                 auto[i, j] = q.front();
//                 q.pop();

//                 if(grid[i][j] >= query){
//                     continue;
//                 }

//                 points++;

//                 for(auto& dir : directions){
//                     int i_ = i + dir[0];
//                     int j_ = j + dir[1];
//                     if(i_ >=0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]){
//                         q.push({i_, j_});
//                         visited[i_][j_] = true;
//                     }
//                 }
//             }
//         }
//         return points;
//     }
//     vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
//         m = grid.size();
//         n = grid[0].size();

//         vector<int>result;

//         for(int& query : queries){
//             int points = bfs(grid, query);
//             result.push_back(points);
//         }
//         return result;
//     }
// };