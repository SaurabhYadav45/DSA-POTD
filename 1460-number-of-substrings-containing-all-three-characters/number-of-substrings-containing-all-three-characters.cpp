class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int count = 0;
        vector<int>freq(3, 0);
        int i=0;
        int j=0;
        
        while(j < n){
            char ch = s[j];
            freq[ch-'a']++;
            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
                count += n-j;
                freq[s[i] -'a']--;
                i++;
            }
            j++;
        }
        return count;
    }
};


//                  ********** BRUTE FORCE ***********

// class Solution {
// public:
//     bool checkValidSubstring(string str){
//         vector<bool>v(3, false);

//         for(char&ch : str){
//             v[ch-'a'] = true;
//         }

//         for(bool b : v){
//             if(b == false){
//                 return false;
//             }
//         }
//         return true;
//     }
//     int numberOfSubstrings(string s) {
//         int n = s.length();

//         int count = 0;
        
//         for(int i=0; i<n; i++){
//             for(int j=i; j<n; j++){
//                 string str = s.substr(i, j-i+1);
//                 if(str.length() >= 3 && checkValidSubstring(str)){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };