class Solution {
public:
    int n ;
    vector<string>result;
    void solve(string& s, string& curr, int idx, unordered_map<char, string>&mp){
        if(idx >= n){
            result.push_back(curr);
            return;
        }

        char i = s[idx];
        string str = mp[i];

        for(auto&ch: str){
            curr.push_back(ch);
            solve(s, curr, idx+1, mp);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string d) {
        if(d.empty()) return result;
        n = d.length();
        unordered_map<char, string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        string curr = "";
        solve(d, curr, 0, mp);
        return result;
    }
};








// class Solution {
// public:
// void backtrack(const string& d, int i, string& curr,vector<string>& res, const vector<string>& digitToLetters) {
//         if (i == d.size()) {
//             res.push_back(curr);
//             return;
//         }
//         int di = d[i] - '0';
//         const string& l = digitToLetters[di];
        
//         for (char l : l) {
//             curr.push_back(l);
//             backtrack(d,i+1,curr,res,digitToLetters);
//             curr.pop_back();
//         }
//     }
//     vector<string> letterCombinations(string d) {
//         if (d.empty()) return {};
        
//         vector<string> res;
//         string curr;
//         vector<string> digitToLetters = {
//             "", "", "abc", "def", "ghi", "jkl", 
//             "mno", "pqrs", "tuv", "wxyz"
//         };
//         backtrack(d, 0,curr,res,digitToLetters);
//         return res;
//     }
// };