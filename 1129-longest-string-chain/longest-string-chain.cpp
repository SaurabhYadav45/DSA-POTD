class Solution {
public:
    static bool myComp(string& s1, string& s2){
        return s1.length() < s2.length();
    }

    bool isPredecessor(string&s1, string&s2){
        int n1 = s1.length();
        int n2 = s2.length();
        if(n1 >= n2 || n2-n1 != 1) return false;

        int i = 0, j=0;
        while(i < n1 && j < n2){
            if(s1[i] == s2[j]){
                i++;
            }
            j++;
        }
        return i == n1;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), myComp);
        vector<int>dp(n, 1);
        // dp[i] = longest possible word chain in words[0..i]
        int maxL = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(isPredecessor(words[j], words[i])){
                    dp[i] = max(dp[i], dp[j]+1);
                    maxL = max(maxL, dp[i]);
                }
            }
        }
        return maxL;
    }
};



// class Solution {
// public:
//     static bool myComp(string& s1, string& s2){
//         return s1.length() < s2.length();
//     }

//     bool isPredecessor(string&s1, string&s2){
//         int n1 = s1.length();
//         int n2 = s2.length();
//         if(n2-n1 > 1) return false;

//         int i = 0, j=0;
//         while(i < n1 && j < n2){
//             if(s1[i] == s2[j]){
//                 i++;
//             }
//             j++;
//         }
//         return i == n1;
//     }

//     int solve(int i, int prev, vector<string>& words, vector<vector<int>>&dp){
//         if(i >= words.size()){
//             return 0;
//         }

//         if(dp[i][prev+1] != -1){
//             return dp[i][prev+1];
//         }

//         int take = 0;
//         if(prev == -1 || (words[i].length() > words[prev].length() && isPredecessor(words[prev], words[i]))){
//             take = 1 + solve(i+1, i, words, dp);
//         }
//         int skip = solve(i+1, prev, words, dp);

//         return dp[i][prev+1] = max(take, skip);
//     }
//     int longestStrChain(vector<string>& words) {
//         int n = words.size();
//         sort(words.begin(), words.end(), myComp);
//         vector<vector<int>>dp(n, vector<int>(n+1, -1));
//         return solve(0, -1, words, dp);
//     }
// };