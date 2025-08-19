//Approach-4 (Smart approach)
//T.C : O(n^2)
//S.C : o(1)
class Solution {
public:
    int count = 0;
    void check(string& s, int i, int j, int n) {
        
        while(i >= 0 && j < n && s[i] == s[j]) {
            count++;
            i--; //expanding from center
            j++; //expanding from center
        }
    }
    int countSubstrings(string s) {
        int n = s.length();
        count = 0;
        
        /*
            
    Every single character in the string is a center for possible odd-length palindromes: check(s, i, i);
    Every pair of consecutive characters in the string is a center for possible even-length palindromes: check(s, i, i+1);.

        */
        for(int i = 0; i<n; i++) {
            check(s, i, i, n);
            check(s, i, i+1, n);
        }
        return count;
    }
};




//      *************** Bottom Up ***********

// class Solution {
// public:
//     int countSubstrings(string s) {
//         int n = s.size();
//         int count = 0;
//         vector<vector<bool>>dp(n, vector<bool>(n));

//         for(int l = 1; l <=n; l++){
//             for(int i=0; i+l-1<n; i++){
//                 int j = i+l-1;
//                 if(i == j){
//                     dp[i][j] = true;
//                 }
//                 else if(i+1 == j){
//                     dp[i][j] = (s[i] == s[j]);
//                 }
//                 else{
//                     if(s[i] == s[j] && dp[i+1][j-1]){
//                         dp[i][j] = true;
//                     }
//                 }

//                 count += dp[i][j];
//             }
//         }
//         return count;
//     }
// };


//       ************* Rec + Memo *************

// class Solution {
// public:
//     int t[1000][1000];
//     int checkPalindrome(string& s, int i, int j ){
//         if(i > j) return 1;

//         if(t[i][j] != -1){
//             return t[i][j];
//         }

//         if(s[i] == s[j]){
//             return checkPalindrome(s, i+1, j-1);
//         }
//         return t[i][j] = 0;
//     }
//     int countSubstrings(string s) {
//         int n = s.size();
//         int count = 0;
//         memset(t, -1, sizeof(t));

//         for(int i=0; i<n; i++){
//             for(int j=i; j<n; j++){
//                 if(checkPalindrome(s, i, j)){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };