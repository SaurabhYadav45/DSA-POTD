class Solution {
public:
    int n;
    unordered_map<int, int>mp;
    bool solve(int i, int prevJump, vector<int>& stones, vector<vector<int>>&dp){
        if(i == n-1){
            return true;
        }

        if(dp[i][prevJump] != -1){
            return dp[i][prevJump];
        }

        bool result = false;

        for(int nextJump = prevJump-1; nextJump <= prevJump+1; nextJump++){
            int nextStone = stones[i] + nextJump;
            if(nextJump > 0){
                if(mp.find(nextStone) != mp.end()){
                    result = result || solve(mp[nextStone], nextJump, stones, dp);
                }
            }
        }
        return dp[i][prevJump] = result;
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        for(int i=0; i<n; i++){
            mp[stones[i]] = i;
        }
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(0, 0, stones, dp);
    }
};