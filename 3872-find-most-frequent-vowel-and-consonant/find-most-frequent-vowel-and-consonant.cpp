class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int>mp;
        unordered_map<char, int>mp2;

        for(char& ch : s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o'|| ch == 'u'){
                mp[ch]++;
            }
            else{
                mp2[ch]++;
            }
        }

        int maxFreq = 0;
        for(auto& it: mp){
            maxFreq = max(maxFreq, it.second);
        }

        int maxFreq2 = 0;
        for(auto& it: mp2){
            maxFreq2 = max(maxFreq2, it.second);
        }

        return maxFreq + maxFreq2;
    }
};