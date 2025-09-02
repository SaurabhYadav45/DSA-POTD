class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        unordered_map<char, int>mp;
        for(char&ch : t){
            mp[ch]++;
        }

        int minLength = INT_MAX;
        int countRequired = t.length();
        int startIdx = -1;
        int i=0, j=0;

        while(j < n){
            char ch = s[j];
            if(mp[ch] > 0){
                countRequired--;
            }
            mp[ch]--;

            while(countRequired == 0){
                if(minLength > (j-i+1)){
                    minLength = (j-i+1);
                    startIdx = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0){
                    countRequired++;
                }
                i++;
            }
            j++;
        }
        return (minLength == INT_MAX) ? "" : s.substr(startIdx, minLength);
    }
};