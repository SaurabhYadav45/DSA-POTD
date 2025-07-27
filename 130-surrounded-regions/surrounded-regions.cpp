class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions{{0,1}, {0,-1}, {1, 0}, {-1, 0}};
    
    void dfs(vector<vector<char>>& board, int i, int j){
        board[i][j] = 'B'; // Mark safe

        for(auto& dir : directions){
            int x = i + dir[0];
            int y = j + dir[1];
            if(x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O'){
                dfs(board, x, y);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;

        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O') dfs(board, i, 0);       // Left border
            if(board[i][n-1] == 'O') dfs(board, i, n-1);   // Right border
        }

        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O') dfs(board, 0, j);       // Top border
            if(board[m-1][j] == 'O') dfs(board, m-1, j);   // Bottom border
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'B'){
                    board[i][j] = 'O'; // Restore safe
                } else if(board[i][j] == 'O'){
                    board[i][j] = 'X'; // Flip surrounded
                }
            }
        }
    }
};
