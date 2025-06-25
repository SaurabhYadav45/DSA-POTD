// class Solution {
// public:
//     void solve(string& s, int i, int currCount, int& maxCount, unordered_set<string>&st){
//         if(i >= s.length()){
//             maxCount = max(maxCount, currCount);
//             return;
//         }

//         for(int j=i; j<s.length(); j++){
//             string sub = s.substr(i, j-i+1);
//             if(st.find(sub) == st.end()){
//                 st.insert(sub);
//                 solve(s, j+1, currCount+1, maxCount, st);
//                 st.erase(sub);
//             }
//         }
//     }
//     int maxUniqueSplit(string s) {
//         unordered_set<string>st;
//         int currCount = 0;
//         int maxCount = 0;
//         int i=0;

//         solve(s, i, currCount, maxCount, st);

//         return maxCount;
//     }
// };



class Solution {
public:
    int n;
    void solve(string& s, int idx, int& count, int& maxCount, unordered_set<string>&st){
        if(idx >= n){
            maxCount = max(maxCount, count);
            return;
        }

        for(int L=1; L<=n; L++){
            string temp = s.substr(idx, L);
            if(st.find(temp) == st.end()){
                st.insert(temp);
                count++;
                solve(s, idx+L, count, maxCount, st);
                count--;
                st.erase(temp);
            }
        }
    }
    int maxUniqueSplit(string s) {
       n = s.length();
       int count = 0;
       int maxCount = 0;
       unordered_set<string>st;
       solve(s, 0, count, maxCount, st);
       return maxCount;
    }
};








