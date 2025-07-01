class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int count = 0;
        int i=0, j=1;
        while(j < n){
            if(word[j] == word[i]){
                count++;
            }
            else{
                i = j;
            }
            j++;
        }
        return count+1;
    }
};











// class Solution {
// public:
//     int possibleStringCount(string word) {
//         vector<int>freq(26, 0);
//         for(char& ch : word){
//             freq[ch-'a']++;
//         }

//         int count = 0;
//         for(int& f : freq){
//             if(f == 0) continue;
//             count += f-1;
//         }
//         return count+1;
//     }
// };