// class Solution {
// public:
//     vector<vector<string>>result;
//     int N ;

//     bool isValid(vector<string>&board, int row, int col){
//         // upward
//         for(int i=row; i>=0; i--){
//             if(board[i][col] == 'Q'){
//                 return false;
//             }
//         }

//         // upward leftward diagonal
//         for(int i=row, j=col; i>=0 && j >= 0; i--, j--){
//             if(board[i][j] == 'Q'){
//                 return false;
//             }
//         }

//         //upward rightward diagonal
//         for(int i=row, j=col; i>=0 && j < N; i--, j++){
//             if(board[i][j] == 'Q'){
//                 return false;
//             }
//         }
//         return true;
//     }

//     void solve(vector<string>&board, int row){
//         // Base case
//         if(row >= N){
//             result.push_back(board);
//             return;
//         }

//         for(int col=0; col <N; col++){
//             if(isValid(board, row, col)){
//                 board[row][col] = 'Q';
//                 solve(board, row+1);
//                 board[row][col] = '.';
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         N = n;
//         vector<string>board(n, string(n, '.'));
//         solve(board, 0);

//         return result;
//     }
// };



//               Optimized version

class Solution {
public:
    vector<vector<string>>result;
    unordered_set<int>upward;
    unordered_set<int>leftward;
    unordered_set<int>rightward;
    int N ;

    void solve(vector<string>&board, int row){
        // Base case
        if(row >= N){
            result.push_back(board);
            return;
        }

        for(int col=0; col <N; col++){
            if(upward.find(col) == upward.end() && leftward.find(row-col) == leftward.end() && rightward.find(row+col) == rightward.end()){
                board[row][col] = 'Q';
                upward.insert(col);
                leftward.insert(row-col);
                rightward.insert(row+col);
                solve(board, row+1);
                // backtracking
                board[row][col] = '.';
                upward.erase(col);
                leftward.erase(row-col);
                rightward.erase(row+col);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string>board(n, string(n, '.'));
        solve(board, 0);

        return result;
    }
};