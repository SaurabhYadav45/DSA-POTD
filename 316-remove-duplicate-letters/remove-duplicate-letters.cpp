class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool>visited(26, false);
        vector<int>freq(26, 0);
        for(int i=0; i<s.length(); i++){
            freq[s[i] - 'a']++;
        }

        stack<char>st;
        for(int i=0; i<s.length(); i++){
            freq[s[i] - 'a']--;

            if (visited[s[i] - 'a']) continue;
            while(!st.empty() && s[i] <= st.top() && freq[st.top() - 'a'] > 0){
                visited[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i] - 'a'] = true;
        }
        
        string result = "";
        while(!st.empty()){
            char ch = st.top();
            result.push_back(ch);
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};