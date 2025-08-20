class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        // Blue print 
        vector<vector<bool>>isPalindrome(n, vector<bool>(n, false));
        for(int i = 0; i<n; i++) {
            isPalindrome[i][i] = true;
        }
        for(int l=2; l<n+1; l++){
            for(int i = 0; i+l-1 < n; i++){
                int j = i+l-1;
                if(s[i] == s[j]){
                    if(l == 2){
                        isPalindrome[i][j] = true;
                    }
                    else if(isPalindrome[i+1][j-1] == true){
                        isPalindrome[i][j] = true;
                    }
                }
            }
        }

        // dp[i] = min. cuts needed in sting s[0..i] to make it it palindrome
        vector<int>dp(n);   
        for(int i=0; i<n; i++){
            if(isPalindrome[0][i]){
                dp[i] = 0;
            }
            else{
                dp[i] = INT_MAX;
                for(int k = 0; k<i; k++){
                    if(isPalindrome[k+1][i] == true && (1 + dp[k]) < dp[i]){
                        dp[i] = 1 + dp[k];
                    }
                }
            }
        }
        return dp[n-1];
    }
};


// class Solution {
// public:
//     int n;
//     int solve(int i, int j, string&s, vector<vector<bool>>&isPalindrome, vector<vector<int>>&dp){
//         if(i >= j){
//             return 0;
//         }

//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }

//         if(isPalindrome[i][j]){
//             return 0;
//         }

//         int partition = INT_MAX;
//         for(int k=i; k<j; k++){
//             int temp = 1 + solve(i, k, s, isPalindrome, dp) + solve(k+1, j, s, isPalindrome, dp);
//             partition = min(partition, temp);
//         }
        
//         return dp[i][j] = partition;
//     }
//     int minCut(string s) {
//         n = s.length();
//         // Blue print 
//         vector<vector<bool>>isPalindrome(n, vector<bool>(n, false));
//         for(int i = 0; i<n; i++) {
//             isPalindrome[i][i] = true;
//         }
//         for(int l=2; l<n+1; l++){
//             for(int i = 0; i+l-1 < n; i++){
//                 int j = i+l-1;
//                 if(s[i] == s[j]){
//                     if(l == 2){
//                         isPalindrome[i][j] = true;
//                     }
//                     else if(isPalindrome[i+1][j-1] == true){
//                         isPalindrome[i][j] = true;
//                     }
//                 }
//             }
//         }
//         vector<vector<int>>dp(n, vector<int>(n, -1));
//         return solve(0, n-1, s, isPalindrome, dp);
//     }
// };