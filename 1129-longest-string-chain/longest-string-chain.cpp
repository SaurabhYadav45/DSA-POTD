class Solution {
public:
    static bool myComp(string& s1, string& s2){
        return s1.length() < s2.length();
    }

    bool isPredecessor(string&s1, string&s2){
        int n1 = s1.length();
        int n2 = s2.length();
        if(n2-n1 > 1) return false;
        
        int i = 0, j=0;
        while(i < n1 && j < n2){
            if(s1[i] == s2[j]){
                i++;
            }
            j++;
        }
        return i == n1;
    }

    int solve(int i, int prev, vector<string>& words, vector<vector<int>>&dp){
        if(i >= words.size()){
            return 0;
        }

        if(dp[i][prev+1] != -1){
            return dp[i][prev+1];
        }

        int take = 0;
        if(prev == -1 || (words[i].length() > words[prev].length() && isPredecessor(words[prev], words[i]))){
            take = 1 + solve(i+1, i, words, dp);
        }
        int skip = solve(i+1, prev, words, dp);

        return dp[i][prev+1] = max(take, skip);
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), myComp);
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return solve(0, -1, words, dp);
    }
};


// class Solution {
// public:
//     int n;
//     static bool comparator(string& word1, string&word2){
//         return word1.length() < word2.length();
//     }

//     bool isPredecessor(string&prev, string&curr){
//         int m = prev.length();
//         int n = curr.length();
//         if( m >= n || n-m != 1){
//             return false;
//         }

//         int i=0, j =0 ;
//         while(i < m && j < n){
//             if(prev[i] == curr[j]){
//                 i++;
//             }
//             j++;
//         }
//         return i == m;
//     }

//     int solveUsingMemo(vector<string>& words, int i, int p, vector<vector<int>>&dp){
//         // Base case
//         if( i >= n) return 0;

//         if(p != -1 && dp[i][p] != -1) return dp[i][p] ;

//         int take = 0;
//         if(p == -1 || isPredecessor(words[p], words[i])){
//             take = 1 + solveUsingMemo(words, i+1, i, dp);
//         }
//         int skip = solveUsingMemo(words, i+1, p, dp);
//         int ans = max(take, skip);
//         if(p != -1){
//             dp[i][p] = ans;
//         }
//         return ans;
//     }

//     int solveUsingTabulation(vector<string>& words){
//         vector<int>dp(n+1, 1);

        
//     }

//     int longestStrChain(vector<string>& words) {
//         n = words.size();
//         sort(words.begin(), words.end(), comparator);
//         vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
//         int ans = solveUsingMemo(words, 0, -1, dp);
//         return ans;
//     }
// };