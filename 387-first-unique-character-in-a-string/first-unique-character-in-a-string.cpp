// class Solution {
// public:
//     int firstUniqChar(string s) {
//         int freq[26];
//         // queue<char>q;
//         for(int i =0; i< s.size(); i++){
//             char ch = s[i];
//             freq[ch-'a']++;
//         }
//         for(int i =0; i<s.size(); i++){
//             char ch = s[i];
//             if(freq[ch-'a']  == 1){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };


class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26];
        queue<int>q;
        for(int i =0; i< s.size(); i++){
            char ch = s[i];
            freq[ch-'a']++;
            q.push(i);

            while(!q.empty() && freq[s[q.front()]-'a'] > 1){
                q.pop();
            }
        }
        return q.empty() ? -1 : q.front();
    }
};