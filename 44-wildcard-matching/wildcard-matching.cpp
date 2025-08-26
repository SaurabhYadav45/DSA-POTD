class Solution {
public:
    bool solve(int i, int j, string& p, string& s, vector<vector<int>>&dp){
        if(i < 0 && j < 0)  return true;
        if(i < 0 && j >= 0) return false;
        if(j < 0 && i >= 0){
            for(int si = 0; si<=i; si++){
                if(p[si] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(p[i] == s[j] || p[i] == '?'){
            return dp[i][j] = solve(i-1, j-1, p, s, dp);
        }
        else if(p[i] == '*'){
            return dp[i][j] = solve(i-1, j, p, s, dp) || solve(i, j-1, p, s, dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, p, s, dp);
    }
};


// class Solution {
// public:
//     bool isMatchHelper(string&s, int si, string&p, int pi){
//         if(si == s.size() && pi == p.size()) return true;

//         if(si == s.size() && pi < p.size()){
//             while(pi < p.size()){
//                 if(p[pi] != '*') return false;
//                 pi++;
//             }
//             return true;
//         }
//         if(s[si] == p[pi] || p[pi] == '?'){
//             return isMatchHelper(s, si+1, p, pi+1);
//         }

//         if(p[pi] == '*'){
//             // Treat * as empty or Null
//             bool caseA = isMatchHelper(s, si, p, pi+1);

//             // treat * as any one char
//             bool caseB  = isMatchHelper(s, si+1, p, pi);
//             return caseA || caseB;
//         }
//         return false;
//     }

//     bool isMatch(string s, string p) {
//         int si = 0;
//         int pi = 0;
//         return isMatchHelper(s, si, p, pi);
//     }
// };