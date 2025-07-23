class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalScore = 0;
        string highPriorityPair = x > y ? "ab" : "ba";
        string lowPriorityPair = highPriorityPair == "ab" ? "ba" : "ab";

        // First pass: remove high priority pair
        string stringAfterFirstPass = removeSubstring(s, highPriorityPair);
        int removedPairsCount =
            (s.length() - stringAfterFirstPass.length()) / 2;

        // Calculate score from first pass
        totalScore += removedPairsCount * max(x, y);

        // Second pass: remove low priority pair
        string stringAfterSecondPass =
            removeSubstring(stringAfterFirstPass, lowPriorityPair);
        removedPairsCount =
            (stringAfterFirstPass.length() - stringAfterSecondPass.length()) /
            2;

        // Calculate score from second pass
        totalScore += removedPairsCount * min(x, y);

        return totalScore;
    }

private:
    string removeSubstring(const string& input, const string& targetPair) {
        stack<char> charStack;

        // Iterate through each character in the input string
        for (char currentChar : input) {
            // Check if current character forms the target pair with the top of
            // the stack
            if (currentChar == targetPair[1] && !charStack.empty() &&
                charStack.top() == targetPair[0]) {
                charStack
                    .pop();  // Remove the matching character from the stack
            } else {
                charStack.push(currentChar);
            }
        }

        // Reconstruct the remaining string after removing target pairs
        string remainingChars;
        while (!charStack.empty()) {
            remainingChars += charStack.top();
            charStack.pop();
        }
        reverse(remainingChars.begin(), remainingChars.end());
        return remainingChars;
    }
};




// class Solution {
// public:
//     string removeSubstr(string&s, string& matchStr){
//         // stack<char>st;
//         // for(char& ch : s){
//         //     if(ch == matchStr[1] && !st.empty() && st.top() == matchStr[0]){
//         //         st.pop();
//         //     }
//         //     else{
//         //         st.push(ch);
//         //     }
//         // }

//         // string temp ;
//         // while(!st.empty()){
//         //     temp.push_back(st.top());
//         //     st.pop();
//         // }
//         // reverse(temp.begin(), temp.end());
//         // return temp;
    
//     // Without using Stack :  O(1) Space Complexity
    
//         int i =0; // For writing purpose
//         // J for reading purpose
//         for(int j=0; j<s.length(); j++){
//             s[i] = s[j];
//             i++;

//             if(i >=2 && s[i-2] == matchStr[0] && s[i-1] == matchStr[1]){
//                 i -= 2;
//             }
//         }
//         s.erase(s.begin()+i, s.end());
//         return s;
        
//     }
//     int maximumGain(string s, int x, int y) {
//         int score =0;
//         string maxStr = (x > y) ? "ab" : "ba";
//         string minStr = (x < y) ? "ab" : "ba";
//         int n = s.length();
//         // Max
//         string temp1 = removeSubstr(s, maxStr);
//         int L = temp1.length();
//         int charRemoved = n-L;
//         score += (charRemoved/2)*max(x,y);

//         // Min
//         string temp2 = removeSubstr(temp1, minStr);
//         charRemoved = L - temp2.length();
//         score += (charRemoved/2)*min(x,y);

//         return score;
//     }
// };

