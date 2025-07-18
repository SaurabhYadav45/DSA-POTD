// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         // Base Case
//         if(p.length() == 0){
//             if(s.length() == 0){
//                 return true;
//             }
//         }

//         bool first_char_matched = false;
//         if(s.length() > 0 && (s[0] == p[0] || p[0] == '.')){
//             first_char_matched = true;
//         }

//         if(p.length() >= 2 && p[1] == '*'){
//             bool not_take = isMatch(s, p.substr(2));
//             bool take = first_char_matched && isMatch(s.substr(1), p);
//             return not_take || take;
//         }
//         else{
//             return first_char_matched && isMatch(s.substr(1), p.substr(1));
//         }
//     }
// };




class Solution {
public:
    bool solve(int i, int j, string& s, string& p, vector<vector<int>>&dp) {
        // Base Case
        if(j == p.length()){
            if(i == s.length()){
                return true;
            }
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        bool first_char_matched = false;
        if(i<s.length() && (s[i] == p[j] || p[j] == '.')){
            first_char_matched = true;
        }

        if(j+1<p.length() && p[j+1] == '*'){
            bool not_take = solve(i, j+2, s, p, dp);
            bool take = first_char_matched && solve(i+1, j, s, p, dp);
            return dp[i][j] = not_take || take;
        }
        return dp[i][j] = first_char_matched && solve(i+1, j+1, s, p, dp);
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(21, vector<int>(21, -1));
        return solve(0, 0, s, p, dp);
    }
};