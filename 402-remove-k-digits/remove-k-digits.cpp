class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0; i<num.length(); i++){
            while (!st.empty() && k > 0 && num[i] < st.top()) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // IMP step
        while(!st.empty() && k >0){
            st.pop();
            k--;
        }

        string result = "";
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        
        while(result.size() > 0 && result.back() == '0'){
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        return result == "" ? "0" : result;
    }
};




// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//         string ans;
//         stack<char>st;
//         for(auto digit : num){
//             if(k >0){
//                 while(!st.empty() && st.top() > digit){
//                     st.pop();
//                     k--;
//                     if(k == 0) break;
//                 }
//             }
//             st.push(digit);
//         }
//         // IMPORTANT STEP
//         if(k > 0){
//             while(!st.empty() && k){
//             st.pop();
//             k--;
//             }
//         }
//         while(!st.empty()){
//             ans.push_back(st.top());
//             st.pop();
//         }   
//         while(ans.size() > 0 && ans.back() == '0'){
//             ans.pop_back();
//         }
//         reverse(ans.begin(), ans.end());
//         return ans =="" ? "0" : ans;
//     }
// };