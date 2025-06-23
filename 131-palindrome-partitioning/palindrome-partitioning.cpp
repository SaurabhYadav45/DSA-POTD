class Solution {
public:
    int n;
    vector<vector<string>>result;
    bool isPalindrome(int i, int j, string s){
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(string s, vector<string>&curr, int idx){
        if(idx >= n){
            result.push_back(curr);
            return;
        }

        for(int i=idx; i<n; i++){
            if(isPalindrome(idx, i, s)){
                curr.push_back(s.substr(idx, i-idx+1));
                solve(s, curr, i+1);
                curr.pop_back();  // Backtrack
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<string>curr;
        solve(s, curr, 0);
        return result;
    }
};