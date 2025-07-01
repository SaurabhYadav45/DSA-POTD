// class Solution {
// public:
//     int possibleStringCount(string word) {
//         int n = word.length();
//         int count = 0;
//         int i=0, j=1;
//         while(j < n){
//             if(word[j] == word[i]){
//                 count++;
//             }
//             else{
//                 i = j;
//             }
//             j++;
//         }
//         return count+1;
//     }
// };


class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int count = 0;
        for(int i=1; i<n; i++){
            if(word[i] == word[i-1]){
                count++;
            }
        }
        return count+1;
    }
};




