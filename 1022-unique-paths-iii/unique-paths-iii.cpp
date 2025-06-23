class Solution {
public:
    int m;
    int n;
    int result =0;
    vector<vector<int>>directions{{0,1}, {0,-1}, {1,0}, {-1,0}};
    void solve(int i, int j, int count, vector<vector<int>>& grid, int nonObstacle){
        //Base case
        if(i < 0 || i>=m|| j<0 || j>=n || grid[i][j] == -1){
            return;
        }
        if(grid[i][j] == 2 && count == nonObstacle){
            result++;
            return;
        }
        if(grid[i][j] == 2 && count != nonObstacle){
            return;
        }

        int temp = grid[i][j];
        grid[i][j] = -1;
        count++;

        for(auto& dir : directions){
            int x = i + dir[0];
            int y = j + dir[1];
            solve(x, y, count, grid, nonObstacle);
        }
        
        grid[i][j] = temp;
        count--;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int nonObstacle = 0;
        int x = 0;
        int y = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0 || grid[i][j] == 1 || grid[i][j] == 2){
                    nonObstacle++;
                }
                if(grid[i][j] == 1){
                    x = i;
                    y = j;
                }
            }
        }
        solve(x, y, 1,grid, nonObstacle);
        return result;
    }
};