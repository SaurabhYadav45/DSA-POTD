class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<string>rowStates;
    void generateRowState(string currRow, int m, char prevColor){
        if(m == 0){
            rowStates.push_back(currRow);
            return;
        }

        for(char color: {'R', 'Y', 'G'}){
            if(prevColor == color)continue;

            generateRowState(currRow + color, m-1, color);
        }
    }

    int solve(int remRows, int prevRowIdx, int m, vector<vector<int>>&dp){
        if(remRows == 0){
            return 1;
        }

        if(dp[remRows][prevRowIdx] != -1){
            return dp[remRows][prevRowIdx];
        }

        int totalWays = 0;
        string prevRow = rowStates[prevRowIdx];
        for(int i=0; i<rowStates.size(); i++){
            string nextRow = rowStates[i];
            bool valid  = true;
            for(int j=0; j<m; j++){
                if(prevRow[j] == nextRow[j]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                totalWays = (totalWays + solve(remRows-1, i, m, dp)) % MOD;
            }
        }
        return dp[remRows][prevRowIdx] = totalWays;
    }
    int numOfWays(int n) {
        rowStates.clear();

        generateRowState("", 3, '#');

        int no_row_states = rowStates.size();
        int result = 0;
        vector<vector<int>>dp(n, vector<int>(no_row_states, -1));
        for(int i=0; i<no_row_states; i++){
            result = (result + solve(n-1, i, 3, dp)) % MOD;
        }
        return result;
    }
};