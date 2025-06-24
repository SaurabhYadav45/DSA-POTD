class Solution {
public:
    int m, n;
    int result = 0;
    vector<vector<int>>directions{{0,1}, {0,-1}, {1,0}, {-1,0}};
    void solve(vector<vector<int>>& grid, int i, int j, int sum){
        result = max(result, sum);

        int temp = grid[i][j];
        grid[i][j] = 0;
        
        for(auto& dir : directions){
            int x = i + dir[0];
            int y = j + dir[1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 0) {
                solve(grid, x, y, sum + grid[x][y]);
            }
        }

        grid[i][j] = temp;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] != 0){
                    solve(grid, i, j, grid[i][j]);
                }
            }
        }
        return result;
    }
};