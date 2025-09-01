class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        // if()
        unordered_map<char, int>mp;
        int i=0, j=0;
        int maxLength = 0;

        while(j < n){
            char ch = s[j];
            mp[ch]++;
            while(mp[ch] > 1){
                mp[s[i]]--;
                i++;
            }
            maxLength = max(maxLength, j-i+1);
            j++;
        }
        return maxLength;
    }
};