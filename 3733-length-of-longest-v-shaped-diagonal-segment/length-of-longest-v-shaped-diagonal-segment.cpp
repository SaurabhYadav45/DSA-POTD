class Solution {
public:
    int m, n;
    int memo[501][501][4][2];
    vector<vector<int>>directions{{1,1}, {1,-1}, {-1,-1}, {-1,1}};
    int solve(int i, int j, int d, bool canTurn, int val, vector<vector<int>>& grid){
        int x = i + directions[d][0];
        int y = j + directions[d][1];

        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != val){
            return 0;
        }

        if(memo[x][y][d][canTurn] != -1){
            return memo[x][y][d][canTurn];
        }

        int length = 0;

        int keepMoving = 1 + solve(x, y, d, canTurn, (val==2?0:2), grid);
        length = max(length, keepMoving);

        if(canTurn){
            int takeTurn = 1 + solve(x, y, (d+1)%4, false, (val==2?0:2), grid);
            length = max(length, takeTurn);
        }
        return length;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int result = 0;

        memset(memo, -1, sizeof(memo));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    for(int d=0; d<=3; d++){
                        result =  max(result, 1+solve(i, j, d, true, 2, grid));
                    }
                }
            }
        }
        return result;
    }
};