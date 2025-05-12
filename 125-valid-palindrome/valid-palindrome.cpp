class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
        // unordered_set<char>st;

        // for(char ch='a'; ch <='z'; ch++){
        //     st.insert(ch);
        // }

        
        for(int i =0; i<s.size(); i++){
            char ch = s[i];
            if(isalnum(ch)){
                ans.push_back(tolower(ch));
            }
        }

        string s2 = ans;
        reverse(s2.begin(), s2.end());
        if(ans == s2){
            return true;
        }
        return false;
    }
};