class Solution {
public:
    bool isValid(string word) {
        unordered_set<char>st{'a','e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        if(word.length() < 3) return false;
        for(char& ch: word){
            if(!isalnum(ch)) return false;
        }

        int count = 0;
        for(char& ch: word){
            if(st.find(ch) != st.end()){
                count++;
                break;
            }
        }
        if(count == 0) return false;

        count = 0;
        for(char& ch: word){
            if(isalpha(ch) && st.find(ch) == st.end()){
                 count++;
                 break;
            }
        }
        if(count == 0) return false;

        return true;
    }
};