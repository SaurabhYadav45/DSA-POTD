class Solution {
public:
    int m, n;
    vector<vector<int>>directions{{0,1}, {0,-1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<int>>& grid, int i, int j){
        grid[i][j] = 0;

        for(auto& dir: directions){
            int x = i + dir[0];
            int y = j + dir[1];
            if(x >= 0 && x  < m && y >= 0 && y < n && grid[x][y] == 1){
                dfs(grid, x, y);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for(int i=0; i<m; i++){
            int j = 0;
            if(grid[i][j] == 1){
                dfs(grid, i, j);
            }

            j = n-1;
            if(grid[i][j] == 1){
                dfs(grid, i, j);
            }
        }

        for(int j=0; j<n; j++){
            int i = 0;
            if(grid[i][j] == 1){
                dfs(grid, i, j);
            }

            i = m-1;
            if(grid[i][j] == 1){
                dfs(grid, i, j);
            }
        }

        int count=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1)count++;
            }
        }
        return count;
    }
};