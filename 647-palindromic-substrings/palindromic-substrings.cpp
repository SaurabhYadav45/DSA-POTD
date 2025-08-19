class Solution {
public:
    int t[1000][1000];
    int checkPalindrome(string& s, int i, int j ){
        if(i > j) return 1;

        if(t[i][j] != -1){
            return t[i][j];
        }

        if(s[i] == s[j]){
            return checkPalindrome(s, i+1, j-1);
        }
        return t[i][j] = 0;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        memset(t, -1, sizeof(t));

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(checkPalindrome(s, i, j)){
                    count++;
                }
            }
        }
        return count;
    }
};
    
//     // int checkPalindromicSubstring(string s, int i, int j ){
//     //     int count =0;
//     //     while( i>=0 && j< s.length() && s[i] == s[j]){
//     //         count++;
//     //         i--;
//     //         j++;
//     //     }
//     //     return count;
//     // }

//     bool checkP(string&s , int i, int j, vector<vector<int>>&dp){
//         // base case
//         if(i > j) return true;

//         if(dp[i][j] != -1) return dp[i][j];

//         if(s[i] == s[j]){
//            return  dp[i][j] =  checkP(s,i+1, j-1, dp);
//         }
//         return dp[i][j] =  false;
//     }

//     int usingTabulation(string&s){
//         int n= s.length();
//         vector<vector<bool>>dp(n+1, vector<bool>(n+1, false));
//         int count = 0;

//         for(int L =1; L <=n ;L++){
//             for(int i=0; i+L-1<n; i++){
//                 int j = i+L-1;
//                 if(i == j){          // ONE LENGTH
//                     dp[i][i] = true;
//                 }
//                 else if(i+1 == j){   //Two length
//                     dp[i][j] = (s[i] == s[j]);
//                 }
//                 else{      // Greater than 2 length
//                     dp[i][j] = ((s[i] == s[j]) && dp[i+1][j-1]);
//                 }
//                 if(dp[i][j] == true){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }

//     int countSubstrings(string s) {
//         // int totalCount = 0;
//         // for(int center = 0; center < s.length(); center++){

//         //     int oddCount = checkPalindromicSubstring(s, center, center );
//         //     int evenCount = checkPalindromicSubstring(s, center, center+1 );

//         //     totalCount = totalCount + oddCount + evenCount;
//         // }
//         //  return totalCount;

//         // Method-2

//         // int n = s.length();
//         // int count = 0;
//         // vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
//         // for(int i=0; i<n; i++){
//         //     for(int j=i; j<n; j++){
//         //         if(checkP(s, i, j, dp)){
//         //             count++;
//         //         }
//         //     }
//         // }
//         // return count;

//         // Method-3 : Tabulation
//         int count = usingTabulation(s);
//         return count;
//     }
// };