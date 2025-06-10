class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int>mp;
        int odd_max_freq = 0;
        int even_max_freq = 0;
        int odd_min_freq = INT_MAX;
        int even_min_freq = INT_MAX;

        for(char&ch : s){
            mp[ch]++;
        }

        for(auto& it: mp){
            if(it.second % 2 == 0){
                even_max_freq = max(even_max_freq, it.second);
                even_min_freq = min(even_min_freq, it.second);
            }
            else{
                odd_max_freq = max(odd_max_freq, it.second);
                odd_min_freq = min(odd_min_freq, it.second);
            }
        }

        int result1 = (odd_min_freq - even_max_freq);
        int result2  = odd_max_freq - even_min_freq;
        return max(result1, result2);
    }
};