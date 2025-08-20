class Solution {
public:
    int n;
        bool isPalindrome(string& s, int i, int j){
            while(i <= j){
                if(s[i] != s[j]){
                    return false;
                }
                i++;
                j--;
            }
            return true;
        }
    void solve(int i, string&s, vector<string>&curr, vector<vector<string>>&result, vector<vector<bool>>&isPalindrome){
        if(i >= n){
            result.push_back(curr);
            return;
        }

        for(int j=i; j<n; j++){
            if(isPalindrome[i][j]){
                curr.push_back(s.substr(i, j-i+1));
                solve(j+1, s, curr, result, isPalindrome);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<string>curr;
        vector<vector<string>>result;

        // Blue print 
        vector<vector<bool>>isPalindrome(n, vector<bool>(n));
        for(int i=0; i<n; i++){
            isPalindrome[i][i] = true;
        }
        for(int l=2; l<n+1; l++){
            for(int i = 0; i+l-1 < n; i++){
                int j = i+l-1;
                if(s[i] == s[j]){
                    if(l == 2){
                        isPalindrome[i][j] = true;
                    }
                    else if(isPalindrome[i+1][j-1] == true){
                        isPalindrome[i][j] = true;
                    }
                }
            }
        }
        solve(0, s, curr, result, isPalindrome);
        return result;
    }
};


//           *********** Backtracking *************

// class Solution {
// public:
//     int n;
//     vector<vector<string>>result;
//     bool isPalindrome(int i, int j, string& s){
//         while(i <= j){
//             if(s[i] != s[j]){
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true;
//     }
//     void solve(string& s, vector<string>&curr, int idx){
//         if(idx >= n){
//             result.push_back(curr);
//             return;
//         }

//         for(int i=idx; i<n; i++){
//             if(isPalindrome(idx, i, s)){
//                 curr.push_back(s.substr(idx, i-idx+1));
//                 solve(s, curr, i+1);
//                 curr.pop_back();  // Backtrack
//             }
//         }
//     }
//     vector<vector<string>> partition(string s) {
//         n = s.length();
//         vector<string>curr;
//         solve(s, curr, 0);
//         return result;
//     }
// };