class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int num = 0;
        int result = 0;
        int sign = 1;
        for(char ch : s){
            if(isdigit(ch)){
                num = (long long)num*10 + ch - '0';
            }
            if(ch == '+'){
                result = result + num*sign;
                num = 0;
                sign = 1;
            }
            if(ch == '-'){
                result = result + num*sign;
                num = 0;
                sign = -1;
            }
            if(ch == '('){
                st.push(result);
                st.push(sign);
                result = 0;
                num = 0;
                sign = 1;
            }
            if(ch == ')'){
                result = result + num*sign;
                result = result*st.top();
                st.pop();
                result += st.top();
                st.pop();
                num = 0;
            }
            
        }
        result += num*sign;
        return result;
    }
};