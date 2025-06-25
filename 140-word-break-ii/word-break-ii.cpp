class Solution {
public:
    int n;
    void solve(string s, unordered_set<string>&st, int idx, string curr, vector<string>&result){
        //Base case
        if(idx == n){
            curr.pop_back(); // remove trailing spaces
            result.push_back(curr);
            return;
        }
        // if(st.find(s) != st.end()){
        //     //
        // }

        for(int L=1; idx+L<=n; L++){
            string temp = s.substr(idx, L);
            if(st.find(temp) != st.end()){
                string prev = curr;
                curr += temp + " ";
                solve(s, st, idx+L, curr, result);
                curr = prev; // Backtrack
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        unordered_set<string>st;
        for(string& word: wordDict){
            st.insert(word);
        }
        string curr = "";
        vector<string>result;
        solve(s, st, 0, curr, result);
        return result;
    }
};