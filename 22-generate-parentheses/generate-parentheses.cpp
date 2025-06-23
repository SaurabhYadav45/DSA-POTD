// class Solution {
// public:
    
//     vector<string>ans;

//     // bool isValid(string& curr){
//     //     stack<char>st;
//     //     for(auto & ch : curr){
//     //         if(ch == '('){
//     //             st.push(ch);
//     //         }
//     //         else{
//     //             if(!st.empty() && st.top() == '('){
//     //                 st.pop();
//     //             }
//     //             else{
//     //                 return false;
//     //             }
//     //         }
//     //     }
//     //     if(st.empty()) return true;
//     //     return false;
//     // }

//     void solve(string& curr, int n, int open, int close){
//         if(curr.length() == 2*n){
//             // if(isValid(curr)){
//             //     ans.push_back(curr);
//             // }
//             // return;
//         }

//         if(open < n){
//             curr.push_back('(');
//             solve(curr, n, open+1, close);
//             curr.pop_back();
//         }

//         if(close < open){
//             curr.push_back(')');
//             solve(curr, n, open, close+1);
//             curr.pop_back();
//         }
//     }
//     vector<string> generateParenthesis(int n) {
//         int open = 0;
//         int close = 0;
//         string curr = "";
//         solve(curr, n, open, close);
//         return ans;
//     }
// };


class Solution {
public:
    vector<string>ans;
    void solve(string curr, int n, int open, int close){
        if(curr.length() == 2*n){
            ans.push_back(curr);
        }

        if(open < n){
            curr.push_back('(');
            solve(curr, n, open+1, close);
            curr.pop_back();
        }

        if(close < open){
            curr.push_back(')');
            solve(curr, n, open, close+1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        string curr = "";
        solve(curr, n, open, close);
        return ans;
    }
};