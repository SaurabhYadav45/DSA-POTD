class Solution {
public:
    bool checkPalindrome(string s){
        int i = 0;
        int j = s.length()-1;

        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string ans = "";
        
        for(int i =0; i<s.size(); i++){
            char ch = s[i];
            if(isalnum(ch)){
                ans.push_back(tolower(ch));
            }
        }

        if(checkPalindrome(ans)){
            return true;
        }
        return false;
        // string s2 = ans;
        // reverse(s2.begin(), s2.end());
        // if(ans == s2){
        //     return true;
        // }
        // return false;
    }
};