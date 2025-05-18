class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<string>columnStates;
    void findColumnStates(string currColumn, int rowsRemaining, char prevColor){
        if(rowsRemaining == 0){
            columnStates.push_back(currColumn);
            return;
        }

        for(char color : {'R', 'G', 'B'}){
            if(color == prevColor)continue;

            findColumnStates(currColumn+color, rowsRemaining-1, color);
        }
    }

    int solve(int remColumns, int prevColumnIdx, int m, vector<vector<int>>&dp){
        if(remColumns == 0){
            return 1;
        }

        if(dp[remColumns][prevColumnIdx] != -1){
            return dp[remColumns][prevColumnIdx];
        }

        int totalWays = 0;
        string prevColumn = columnStates[prevColumnIdx];
        for(int nextColumnIdx = 0; nextColumnIdx < columnStates.size(); nextColumnIdx++){
            string nextColumn = columnStates[nextColumnIdx];

            bool valid = true;
            for(int r = 0; r<m; r++){
                if(prevColumn[r] == nextColumn[r]){
                    valid = false;
                    break;
                }
            }
            if (valid) {
                totalWays = (totalWays + solve(remColumns - 1, nextColumnIdx, m, dp)) % MOD;
            }
        }
        return dp[remColumns][prevColumnIdx] = totalWays;
    }
    int colorTheGrid(int m, int n) {
        columnStates.clear();
        findColumnStates("", m, '#');

        int no_of_columnStates = columnStates.size();
        int result = 0;

        vector<vector<int>>dp(n, vector<int>(no_of_columnStates, -1));
        for(int i=0; i<no_of_columnStates; i++){
            result = (result + solve(n-1, i, m, dp)) % MOD;
        }
        return result;
    }
};