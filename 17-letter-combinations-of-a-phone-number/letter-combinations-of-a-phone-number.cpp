class Solution {
public:
void backtrack(const string& d, int i, string& curr,vector<string>& res, const vector<string>& digitToLetters) {
        if (i == d.size()) {
            res.push_back(curr);
            return;
        }
        int di = d[i] - '0';
        const string& l = digitToLetters[di];
        
        for (char l : l) {
            curr.push_back(l);
            backtrack(d,i+1,curr,res,digitToLetters);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string d) {
        if (d.empty()) return {};
        
        vector<string> res;
        string curr;
        vector<string> digitToLetters = {
            "", "", "abc", "def", "ghi", "jkl", 
            "mno", "pqrs", "tuv", "wxyz"
        };
        backtrack(d, 0,curr,res,digitToLetters);
        return res;
    }
};