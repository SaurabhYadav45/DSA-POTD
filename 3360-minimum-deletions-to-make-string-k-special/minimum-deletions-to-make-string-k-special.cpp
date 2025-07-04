// class Solution {
// public:
//     int minimumDeletions(string word, int k) {
//         unordered_map<char, int>mp;
//         unordered_set<char>st;
//         int result = INT_MAX;

//         for(char&ch: word){
//             mp[ch]++;
//             st.insert(ch);
//         }

//         for(auto& ch :st){
//             int freq_i = mp[ch];
//             int delete_freq = 0;
//             for(auto& ch2 : st){
//                 if(ch == ch2)continue;

//                 int freq_j = mp[ch2];
//                 if(freq_j > freq_i + k){
//                     delete_freq += freq_j - freq_i - k;
//                 }
//                 else if(freq_j <  freq_i){
//                     delete_freq += freq_j;
//                 }
//             }
//             result  = min(result, delete_freq);
//         }
//         return result; 
//     }
// };



class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int>freq(26, 0);
        unordered_set<char>st;
        int result = INT_MAX;

        for(char&ch: word){
            freq[ch-'a']++;
            st.insert(ch);
        }

        for(auto& ch :st){
            int freq_i = freq[ch-'a'];
            int delete_freq = 0;
            for(auto& ch2 : st){
                if(ch == ch2)continue;

                int freq_j = freq[ch2-'a'];
                if(freq_j > freq_i + k){
                    delete_freq += freq_j - freq_i - k;
                }
                else if(freq_j <  freq_i){
                    delete_freq += freq_j;
                }
            }
            result  = min(result, delete_freq);
        }
        return result; 
    }
};