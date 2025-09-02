


class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxLength = 0;
        int maxFreq = 0;
        int i=0, j=0;
        vector<int>freq(26, 0);

        while(j < n){
            freq[s[j]-'A']++;
            maxFreq = max(maxFreq, freq[s[j]-'A']);
            while((j-i+1)-maxFreq > k){
                freq[s[i]-'A']--;
                i++;
                for(int i=0; i<26; i++){
                    maxFreq = max(maxFreq, freq[i]);
                }
            }
            maxLength = max(maxLength, (j-i+1));
            j++;
        }
        return maxLength;
    }
};


// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int n = s.length();
//         int maxLength = 0;

//         for(int i=0; i<n; i++){
//             vector<int>freq(26, 0);
//             int maxFreq = 0;
//             for(int j=i; j<n; j++){
//                 freq[s[j]-'A']++;
//                 maxFreq = max(maxFreq, freq[s[j]-'A']);
//                 int changes = (j-i+1) - maxFreq;
//                 if(changes <= k){
//                     int length = j-i+1;
//                     maxLength = max(maxLength, length);
//                 }
//                 else{
//                     break;
//                 }
//             }
//         }
//         return maxLength;
//     }
// };