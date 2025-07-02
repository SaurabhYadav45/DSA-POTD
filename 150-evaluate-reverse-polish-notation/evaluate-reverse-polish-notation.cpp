class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string& s : tokens){
            
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int op1 = st.top(); st.pop();
                int op2 = st.top(); st.pop();
                int temp = 0;

                if (s == "+") temp = op2 + op1;
                else if (s == "-") temp = op2 - op1;
                else if (s == "*") temp = op2 * op1;
                else if (s == "/") temp = op2 / op1;

                st.push(temp);
            }
            else{
                int num = stoi(s);
                st.push(num);
            }
        }
        return st.top();
    }
};