// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         for(int i)
//     }
// };


class Solution {
public:
    bool solve(int sr, int er, int sc, int ec, vector<vector<char>>& board){
        unordered_set<char>st;
        for(int i=sr; i<=er; i++){
            for(int j=sc; j<=ec; j++){
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j]) != st.end()){
                    return true;
                }
                st.insert(board[i][j]);
            }
        }
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check for rows
        for(int row=0; row<9; row++){
            unordered_set<char>st;
            for(int col=0; col<9; col++){
                if(board[row][col] == '.') continue;
                if(st.find(board[row][col]) != st.end()){
                    return false;
                }
                st.insert(board[row][col]);
            }
        }
        // Check for cols
        for(int col=0; col<9; col++){
            unordered_set<char>st;
            for(int row=0; row<9; row++){
                if(board[row][col] == '.') continue;
                if(st.find(board[row][col]) != st.end()){
                    return false;
                }
                st.insert(board[row][col]);
            }
        }
        // check for Sub-boxes
        for(int sr = 0; sr<9; sr += 3){
            int er = sr + 2;
            for(int sc=0; sc<9; sc += 3){
                int ec = sc + 2;
                if(solve(sr, er, sc, ec, board)){
                    return false;
                }
            }
        }
        return true;
    }
};