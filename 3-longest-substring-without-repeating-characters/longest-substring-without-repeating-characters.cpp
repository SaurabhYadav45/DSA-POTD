class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int>mp;
        int i=0, j=0;
        int maxLength = 0;

        while(j < n){
            char ch = s[j];
            if(mp.find(ch) != mp.end()){
                if(mp[ch] >= i){
                    i = mp[ch] + 1;
                }
            }
            int length = j-i+1;
            maxLength = max(maxLength, length);
            mp[ch] = j;
            j++;
        }
        return maxLength;
    }
};


// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.length();
//         unordered_map<char, int>mp;
//         int i=0, j=0;
//         int maxLength = 0;

//         while(j < n){
//             char ch = s[j];
//             mp[ch]++;
//             while(mp[ch] > 1){
//                 mp[s[i]]--;
//                 i++;
//             }
//             maxLength = max(maxLength, j-i+1);
//             j++;
//         }
//         return maxLength;
//     }
// };