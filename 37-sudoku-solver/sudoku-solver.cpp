class Solution {
public:
    bool isValid(char num, int row, int col, vector<vector<char>>& board) {
        // Check for row and col
        for(int j=0; j<9; j++){
            if(board[row][j] == num) return false;
            if(board[j][col] == num) return false;
        }

        // check for Sub-boxes
        int sr = row/3*3;
        int sc = col/3*3;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[sr + i][sc + j] == num){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int row=0; row<9; row++){
            for(int col=0; col<9; col++){
                if(board[row][col] != '.') continue;

                for(char num='1'; num<='9'; num++){
                    if(isValid(num, row, col, board)){
                        board[row][col] = num;
                        if(solve(board)){
                            return true;
                        }
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};