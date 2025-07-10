// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int row = matrix.size();
//         int col = matrix[0].size();
//         int n = row*col;

//         int s = 0;
//         int e = n-1;
//         int mid = s + (e-s)/2;
//         while(s<=e){
//             int rowIndex = mid/col;
//             int colIndex = mid%col;
//             int currNumber = matrix[rowIndex][colIndex];
//             if(currNumber == target){
//                 return true;
//             }
//             else if(currNumber > target){
//                 e = mid-1;
//             }
//             else{
//                 s = mid + 1;
//             }
//             mid = s + (e-s)/2;
//         }
//         return false;
//     }
// };



// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int l = 0, r = m*n-1;
//         int mid;
//         while(l <= r){
//             mid = l + (r-l)/2;
//             if(matrix[mid/n][mid%n] < target){
//                 l = mid+1;
//             }
//             else if(matrix[mid/n][mid%n] > target){
//                 r = mid-1;
//             }
//             else{
//                 return true;
//             }
//         }
//         return false;
//     }
// };



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i=0, j = n-1;
        while(i < m && j >= 0){
            if(matrix[i][j] < target){
                i++;
            }
            else if(matrix[i][j] > target){
                j--;
            }
            else{
                return true;
            }
        }
        return false;
    }
};