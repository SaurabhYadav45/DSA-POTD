// class Solution {
// public:
//     // int m , n; 
//     // vector<vector<int>>directions{{1,0}, {-1,0}, {0,1}, {0,-1}};
//     bool find(vector<vector<char>>& board, string word, int i, int j, int idx){
//         // Base case
//         if(idx == word.size()){
//             return true;
//         }

//         if(i<0 || j<0 || i >= board.size()|| j>= board[0].size() || board[i][j] != word[idx]){
//             return false;
//         }

//         // if(board[i][j] != word[idx]){
//         //     return false;
//         // }

//         char temp = board[i][j];
//         board[i][j] = '$';
        
//         // for(auto& dir : directions){
//         //     int new_i = i + dir[0];
//         //     int new_j = j + dir[1];

//         //     if(find(board, word, new_i, new_j, idx+1)) return true;
//         // }

//         board[i][j] = temp;
//         return false;
//     }
//     bool exist(vector<vector<char>>& board, string word) {
//         int m = board.size();
//         int n = board[0].size();
//         for(int i=0; i<m; ++i){
//             for(int j=0; j<n; ++j){
//                 if(board[i][j] == word[0]){
//                     if(find(board, word, i, j,0)){
//                     return true;
//                     }
//                 } 
//             }
//         }
//         return false;
//     }
// };



// class Solution {
// public:
    
//     bool find(vector<vector<char>>& board, string word, int i, int j, int idx) {
//         // If we have found all characters of the word, return true
//         if (idx == word.size())
//             return true;
        
//         // Boundary check and character mismatch check
//         if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || word[idx] != board[i][j])
//             return false;
        
//         // Temporarily mark the current cell as visited
//         char ch = board[i][j];
//         board[i][j] = '$';
        
//         // Explore the neighbors recursively
//         if (find(board, word, i + 1, j, idx + 1) ||
//             find(board, word, i, j + 1, idx + 1) ||
//             find(board, word, i - 1, j, idx + 1) ||
//             find(board, word, i, j - 1, idx + 1))
//             return true; // If any neighbor leads to finding the word, return true
        
//         // Backtrack
//         board[i][j] = ch;
//         return false;
//     }
    
//     // Main function to check if the word exists on the board
//     bool exist(vector<vector<char>>& board, string word) {
//         int m = board.size(), n = board[0].size();
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 // If the current cell matches the first character of the word, start find from here
//                 if (board[i][j] == word[0]) {
//                     if (find(board, word, i, j, 0)) 
//                         return true;
//                 }
//             }
//         }
//         // If no cell leads to finding the word, return false
//         return false;
//     }
// };


class Solution {
public:
    
    int m;
    int n;
    vector<vector<int>>directions{{0,1}, {0,-1}, {1, 0}, {-1, 0}};
    bool find(int i, int j, vector<vector<char>>&board, string word, int idx){
        // Base case
        if(idx == word.length()){
            return true;
        }

        if(i < 0 || i >=m || j<0 || j>=n || board[i][j] == '$'){
            return false;
        }
        if(word[idx] != board[i][j]){
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '$';

        for(auto&dir: directions){
            int x = i + dir[0];
            int y = j + dir[1];
            if(find(x, y, board, word, idx+1)){
                return true;
            }
        }

        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]){
                    if(find(i, j, board, word, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};