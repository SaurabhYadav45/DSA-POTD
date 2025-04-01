//                   *********** Using Bottom Up ***********
class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        long long n = q.size();
        vector<long long>dp(200001, 0);
        
        for(int i = n-1; i>=0; i--){
            dp[i] = max(q[i][0] + dp[q[i][1] + i +1], dp[i+1]);
        }
        return dp[0];
    }
};



//                    ********** Using Memoization ***********

// class Solution {
// public:
//     int n;
//     long long solve(int i, vector<vector<int>>& questions, vector<long long>&dp){
//         if(i >= n){
//             return 0; 
//         }

//         if(dp[i] != -1){
//             return dp[i];
//         }

//         long long taken = questions[i][0] + solve(i+questions[i][1]+1, questions, dp);

//         long long skip = solve(i+1, questions, dp);

//         dp[i] =  max(taken, skip);
//         return dp[i];
//     }
//     long long mostPoints(vector<vector<int>>& questions) {
//         n = questions.size();
//         vector<long long>dp(n+1, -1);
//         return solve(0, questions, dp);
//     }
// };