class Solution {
public:
    int ROW;
    int COL;
    vector<vector<int>>directions{{1,0}, {-1,0}, {0,1}, {0,-1}};
    bool dfs(vector<vector<int>>&grid, int i, int j){
        if(i<0 || i>=ROW || j <0 || j>=COL || grid[i][j] == 1){
            return false;
        }

        if(i == ROW - 1) return true;
        grid[i][j] = 1;
        for(auto& dir : directions){
            int x = i + dir[0];
            int y = j + dir[1];
            if(dfs(grid, x, y) == true){
                return true;
            }
        }
        return false;
    }
    bool canCross(vector<vector<int>>& cells, int day){
        vector<vector<int>>grid(ROW, vector<int>(COL, 0));

        for(int i=0; i<day; i++){
            int r = cells[i][0]-1;
            int c = cells[i][1]-1;
            grid[r][c] = 1;
        }

        for(int j=0; j<COL; j++){
            if(grid[0][j] == 0 && dfs(grid, 0, j)){
                return true;
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        ROW = row;
        COL = col;
        int low = 1;
        int high = cells.size();
        int lastDay = 0;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(canCross(cells, mid)){
                lastDay = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return lastDay;
    }
};