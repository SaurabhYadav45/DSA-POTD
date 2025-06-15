class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        char x = s[0];
        string s1 = s;
        if(s[0] == '9'){
            for(int i=1; i<s.length(); i++){
                if(s[i] == '9'){
                    continue;
                }
                else{
                    x = s[i];
                    break;
                }
            }

            for(int i=0; i<s.length(); i++){
                if(s[i] == x){
                    s1[i] = '9';
                }
            }
        }
        else{
            for(int i=0; i<s.length(); i++){
                if(s[i] == x){
                    s1[i] = '9';
                }
            }
        }
        string s2 = s;

        for(int i=0; i<s.length(); i++){
            if(s[i] == '1' || s[i] == '0'){
                continue;
            }
            else{
                x = s[i];
                break;
            }
        }

        if(x == s[0]){
           for(int i=0; i<s.length(); i++){
                if(s[i] == x){
                    s2[i] = '1';
                }
            } 
        }
        else{
            for(int i=0; i<s.length(); i++){
                if(s[i] == x){
                    s2[i] = '0';
                }
            }
        }

        int a = stoi(s1);
        int b = stoi(s2);

        return a - b;
    }
};