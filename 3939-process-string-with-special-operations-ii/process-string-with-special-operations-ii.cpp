class Solution {
public:
    char processStr(string s, long long k) {
        long long n = 0;
        for(char&ch : s){
            if(ch == '*') n = max((long long)0, n-1);
            else if(ch == '#') n = n > 0 ? n*2: 0;
            else if(ch == '%') continue;
            else n++;
        }
        if( n <= k) return '.';
        reverse(s.begin(), s.end());

        for(char& ch: s){
            if(ch == '*') n++; 
            else if(ch == '#'){
                n /= 2;
                k = k % n;
            }
            else if(ch == '%'){
                k = n-k-1;
            }
            else{
                n--;
                if(n <= k) return ch;
            }
        }
        return '.';
    }
};