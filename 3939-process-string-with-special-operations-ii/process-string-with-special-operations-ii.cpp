class Solution {
public:
    char processStr(string s, long long k) {
        long long n = 0;  // final length of string

        // lets calculate the final length of the string
        for(char&ch : s){
            if(ch == '*') n = max((long long)0, n-1);
            else if(ch == '#') n = n > 0 ? n*2: 0;
            else if(ch == '%') continue;
            else n++;
        }

        // check if length of final string is less than equal to k, if yes  return '.'
        if( n <= k) return '.';
        // reverse it so that we can perform backward simulation from the starting index (Optional)
        reverse(s.begin(), s.end());

        // perform backward operation
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