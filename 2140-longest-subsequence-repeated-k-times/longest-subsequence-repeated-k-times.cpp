class Solution {
public:
    bool isSubsequence(string&s, string& curr, int k){
        int i=0;
        int j=0;
        int L = curr.length();
        while(i < s.length() && j < k*L){
            if(s[i] == curr[j % L]){
                j++;
            }
            i++;
        }
        return j == k*L;
    }
    void backtracking(string& s, int k, int& maxLength, string& curr, vector<bool>&canUse, vector<int>&requiredFreq, string& result){
        if(curr.length() > maxLength){
            return;
        }
        if((curr.length() > result.length() || (curr.length() == result.length() && curr > result)) && isSubsequence(s, curr, k)){
            result = curr;
        }

        for(int i=0; i<26; i++){
            if(canUse[i] == false || requiredFreq[i] == 0){
                continue;
            }
            // Do
            char ch = i + 'a';
            curr.push_back(ch);
            requiredFreq[i]--;
            // Explore
            backtracking(s, k, maxLength, curr, canUse, requiredFreq, result);
            // Undo
            curr.pop_back();
            requiredFreq[i]++;
        }
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();
        vector<int>freq(26, 0);
        for(char& ch : s){
            freq[ch-'a']++;
        }

        int maxLength = n/k;
        vector<bool>canUse(26, false);
        vector<int>requiredFreq(26, 0);
        for(int i=0; i<26; i++){
            if(freq[i] >= k){
                canUse[i] = true;
                requiredFreq[i] = freq[i]/k;
            }
        }

        string curr="";
        string result = "";
        backtracking(s, k, maxLength, curr, canUse, requiredFreq, result);
        return result;
    }
};







// class Solution {
// public:
//     string longestSubsequenceRepeatedK(string s, int k) {
//         vector<int> freq(26);
//         for (char ch : s) {
//             freq[ch - 'a']++;
//         }
//         vector<char> candidate;
//         for (int i = 25; i >= 0; i--) {
//             if (freq[i] >= k) {
//                 candidate.push_back('a' + i);
//             }
//         }
//         queue<string> q;
//         for (char ch : candidate) {
//             q.push(string(1, ch));
//         }

//         string ans = "";
//         while (!q.empty()) {
//             string curr = q.front();
//             q.pop();
//             if (curr.size() > ans.size()) {
//                 ans = curr;
//             }
//             // generate the next candidate string
//             for (char ch : candidate) {
//                 string next = curr + ch;
//                 if (isKRepeatedSubsequence(s, next, k)) {
//                     q.push(next);
//                 }
//             }
//         }

//         return ans;
//     }

//     bool isKRepeatedSubsequence(const string& s, const string& t, int k) {
//         int pos = 0, matched = 0;
//         int n = s.size(), m = t.size();
//         for (char ch : s) {
//             if (ch == t[pos]) {
//                 pos++;
//                 if (pos == m) {
//                     pos = 0;
//                     matched++;
//                     if (matched == k) {
//                         return true;
//                     }
//                 }
//             }
//         }

//         return false;
//     }
// };