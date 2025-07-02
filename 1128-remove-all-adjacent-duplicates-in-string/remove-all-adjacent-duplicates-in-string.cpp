// class Solution {
// public:
//     string removeDuplicates(string s) {
//         string result = "";
//         result.push_back(s[0]);
//         for(int i=1; i<s.length(); i++){
//             if(!result.empty() && s[i] == result.back()){
//                 result.pop_back();
//             }
//             else{
//                 result.push_back(s[i]);
//             }
//         }
//         return result;
//     }
// };



//              **************** Stack *****************


class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(int i=0; i<s.length(); i++){
            if(!st.empty() && s[i] == st.top()){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        string result = "";
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};