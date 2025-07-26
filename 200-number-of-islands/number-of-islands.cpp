// class Solution {
// public:
//     int m;
//     int n;
//     vector<vector<int>>directions{{0,1}, {0,-1}, {1, 0}, {-1,0}};
//     void bfs(vector<vector<char>>& grid, int i, int j){
//         queue<pair<int, int>>q;
//         q.push({i, j});
//         grid[i][j] = '0';

//         auto isSafe = [&](int x, int y){
//             if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0'){
//                 return false;
//             }
//             return true;
//         };

//         while(!q.empty()){
//             int i = q.front().first;
//             int j = q.front().second;
//             q.pop();
//             for(auto& dir: directions){
//                 int x = i + dir[0];
//                 int y = j + dir[1];
//                 if(isSafe(x, y)){
//                     q.push({x, y});
//                     grid[x][y] = '0';
//                 }
//             }
//         }
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         m = grid.size();
//         n = grid[0].size();

//         int count = 0;

//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 if(grid[i][j] == '1'){
//                     bfs(grid, i, j);
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };




class Solution {
public:
    int m;
    int n;
    vector<vector<int>>directions{{0,1}, {0,-1}, {1, 0}, {-1,0}};
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0'){
            return;
        }

        grid[i][j] = '0';

        for(auto& dir: directions){
            int x = i + dir[0];
            int y = j + dir[1];
            dfs(grid, x, y);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};