class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minRow = 1e9;
        int minCol = 1e9;
        int maxRow = -1;
        int maxCol = -1;
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(grid[i][j] == 1){
                    if(i < minRow){
                        minRow = min(minRow, i);
                    }
                    if(j < minCol){
                        minCol = min(minCol, j);
                    }
                    if(i > maxRow){
                        maxRow = max(maxRow, i);
                    }
                    if(j > maxCol){
                        maxCol = max(maxCol, j);
                    }
                }
            }
        }
        int row = maxRow-minRow;
        int col = maxCol-minCol;
        return (row+1)*(col+1);
    }
};