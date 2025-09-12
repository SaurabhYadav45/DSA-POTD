class Solution {
public:
    bool doesAliceWin(string s) {
        int n = s.length();
        int vowelCount = 0;
        for(char&ch: s){
            if(ch == 'a' || ch == 'e'||ch == 'i' || ch == 'o'||ch == 'u'){
                vowelCount++;
            }
        }

        if(vowelCount == 0)return false;
        return true;
    }
};