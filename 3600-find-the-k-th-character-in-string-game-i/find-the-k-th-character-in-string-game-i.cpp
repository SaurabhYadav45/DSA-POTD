class Solution {
public:
    char kthCharacter(int k) {
        if(k == 1) return 'a';
        string s = "a";
        while(true){
            string curr ="";
            for(char& ch : s){
                char nextCh = ch + 1;
                curr += nextCh;
            }
            s.append(curr);
            if(s.length() >= k){
                break;
            }
        }
        return s[k-1];
    }
};