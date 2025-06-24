// class Solution {
// public:
//     int n ;
//     vector<string>result;
//     void solve(string& s, string& curr, int idx, unordered_map<char, string>&mp){
//         if(idx >= n){
//             result.push_back(curr);
//             return;
//         }

//         char i = s[idx];
//         string str = mp[i];

//         for(auto&ch: str){
//             curr.push_back(ch);
//             solve(s, curr, idx+1, mp);
//             curr.pop_back();
//         }
//     }
//     vector<string> letterCombinations(string d) {
//         if(d.empty()) return result;
//         n = d.length();
//         unordered_map<char, string>mp;
//         mp['2'] = "abc";
//         mp['3'] = "def";
//         mp['4'] = "ghi";
//         mp['5'] = "jkl";
//         mp['6'] = "mno";
//         mp['7'] = "pqrs";
//         mp['8'] = "tuv";
//         mp['9'] = "wxyz";
//         string curr = "";
//         solve(d, curr, 0, mp);
//         return result;
//     }
// };




class Solution {
public:
    int n ;
    vector<string>result;
    void solve(string& s, string& curr, int idx, vector<string>&vec){
        if(idx >= n){
            result.push_back(curr);
            return;
        }

        char i = s[idx];
        string str = vec[i - '0'];

        for(auto&ch: str){
            curr.push_back(ch);
            solve(s, curr, idx+1, vec);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string d) {
        if(d.empty()) return result;
        n = d.length();
        vector<string>vec{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs","tuv", "wxyz" };
        string curr = "";
        solve(d, curr, 0, vec);
        return result;
    }
};
