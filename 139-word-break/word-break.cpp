class Solution {
public:
    bool solve(string s, unordered_set<string>&st, int idx, vector<int>&dp){
        //Base case
        if(idx == s.length()){
            return true;
        }

        if(st.find(s) != st.end()){
            return true;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        for(int L=1; L<=s.length(); L++){
            string temp = s.substr(idx, L);
            if(st.find(temp) != st.end()){
                if(solve(s, st, idx+L, dp)){
                    return dp[idx] = true;
                }
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(string& word: wordDict){
            st.insert(word);
        }
        vector<int>dp(s.length()+1, -1);
        return solve(s, st, 0, dp);
    }
};