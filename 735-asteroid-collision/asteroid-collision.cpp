class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;
        for(int& asteroid : asteroids){
            bool destroy = false;
            if(!st.empty() && st.top() > 0 && asteroid < 0){
                while(!st.empty() && st.top() > 0){
                    if(st.top() + asteroid == 0){
                        st.pop();
                        destroy = true;
                        break;
                    }
                    else if(st.top() + asteroid > 0){
                        destroy = true;
                        break;
                    }
                    else{
                        st.pop();  
                    }
                }
                if(!destroy){
                    st.push(asteroid);
                }
                continue;
            }
            st.push(asteroid);
        }

        int m = st.size();
        vector<int>result(m, 0);
        while(!st.empty()){
            result[m-1] = st.top();
            m--;
            st.pop();
        }
        return result;
    }
};




// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         stack<int>st;
//         for(auto ast : asteroids){
//             bool destroy = false;
//             if(ast > 0){
//                 st.push(ast);
//             }
//             else{
//                 // ast < 0
//                 if(st.empty() || st.top() < 0){
//                     st.push(ast);
//                 }
//                 else{
//                     // ast < 0 and stack top  > 0
//                     // collision
//                     while(!st.empty() && st.top() >0){
//                         if(abs(ast) == st.top()){
//                             st.pop();
//                             destroy  = true;
//                             break;
//                         }
//                         else if(abs(ast) > st.top()){
//                             st.pop();
//                         }
//                         else{
//                             // abs(ast) < st.top()
//                             destroy = true;
//                             break;
//                         }
//                     }
//                     if(!destroy){
//                         st.push(ast);
//                     }
//                 }
//             }
//         }
//         vector<int>ans(st.size());
//         for(int i=st.size()-1; i>=0; i--){
//             ans[i] = st.top();
//             st.pop();
//         }
//         return ans;
//     }
// };