class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin() + 0, 0);
        cuts.push_back(n);
        int m = cuts.size();
        vector<vector<int>>dp(cuts.size(), vector<int>(cuts.size(), 0));
        // State Definition :  dp[i][j] Minimum cost to cut stick b/w i and j

        // Initialization
        // dp[i][i] = 0 for all i < n
        
        // Fill the table
        for(int length = 2; length<m; length++){
            for(int i=0; i+length<m; i++){
                int j = i + length;
                dp[i][j] = INT_MAX;
                for(int k=i+1; k <j; k++){
                    int cost = (cuts[j]-cuts[i]) + dp[i][k] + dp[k][j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        return dp[0][m-1];
    }
};


// class Solution {
// public:
//     int solve(int start, int end, vector<int>& cuts, vector<vector<int>>&dp){
//         if(end-start < 2){
//             return 0;
//         }

//         if(dp[start][end] != -1){
//             return dp[start][end];
//         }

//         int result = INT_MAX;
//         for(int i=start+1; i <= end-1; i++){
//             int cost = cuts[end]-cuts[start];
//             int left = solve(start, i, cuts, dp);
//             int right = solve(i, end, cuts, dp);
//             result = min(result, left+right+cost);
//         }
//         return dp[start][end] = result;
//     }
//     int minCost(int n, vector<int>& cuts) {
//         sort(cuts.begin(), cuts.end());
//         cuts.insert(cuts.begin() + 0, 0);
//         cuts.push_back(n);
//         vector<vector<int>>dp(cuts.size()+1, vector<int>(cuts.size()+1, -1));
//         return solve(0, cuts.size()-1, cuts, dp);
//     }
// };


// class Solution {
// public:
//     int solve(int start, int end, vector<int>& cuts, vector<vector<int>>&dp) {

//         if(dp[start][end] != -1){
//             return dp[start][end];
//         }

//         int cost = INT_MAX;
//         bool canCut = false;

//         for(int& c: cuts){
//             if(c > start && c < end){
//                 canCut = true;
//                 int left = solve(start, c, cuts, dp);
//                 int right = solve(c, end, cuts, dp);
//                 cost = min(cost, left + right + (end-start));
//             }
//         }
//         return dp[start][end] = canCut ? cost : 0;
//     }
//     int minCost(int n, vector<int>& cuts) {
//         vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
//         return solve(0, n, cuts, dp);
//     }
// };