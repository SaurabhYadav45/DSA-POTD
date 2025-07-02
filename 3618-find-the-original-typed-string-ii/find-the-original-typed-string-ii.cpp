// class Solution {
// public:
//     int solve(int i, int count, vector<int>&freq, int k){
//         // Base case
//         if (i >= freq.size()) {
//             return (count < k) ? 1 : 0;
//         }

//         int result = 0;
//         for(int take = 1; take <=freq[i]; take++){
//             if(take + count < k){
//                 result += solve(i+1, count+take, freq, k);
//             }
//         }
//         return result;
//     }
//     int possibleStringCount(string word, int k) {
//         if(k > word.length())
//             return 0;
        
//         vector<int> freq;
//         int count = 1;
//         for(int i = 1; i < word.length(); i++) {
//             if(word[i] == word[i-1]) {
//                 count++;
//             } else {
//                 freq.push_back(count);
//                 count = 1;
//             }
//         }
//         freq.push_back(count);


//         // Find the invalid string
//         int inValidCount = solve(0, 0, freq, k);
//         int totalCount = 1;
//         for(int& cnt : freq){
//             totalCount *= (cnt);
//         }

//         return totalCount - inValidCount;
//     }
// };




// class Solution {
// public:
//     int M = 1e9+7;
//     vector<vector<int>> t;

//     int solve(int i, int count, vector<int>& freq, int k) {
//         if(i >= freq.size()) {
//             if(count < k)
//                 return 1; //found invalid string
//             return 0;
//         }

//         if(t[i][count] != -1) {
//             return t[i][count];
//         }

//         long long result = 0;

//         for(int take = 1; take <= freq[i]; take++) {
//             if(count + take < k) {
//                 result = (result + solve(i+1, count+take, freq, k)) % M;
//             } else {
//                 break;
//             }
//         }

//         return t[i][count] = result;
//     }

//     int possibleStringCount(string word, int k) {
//         if(k > word.length())
//             return 0;
        
//         vector<int> freq;
//         int count = 1;
//         for(int i = 1; i < word.length(); i++) {
//             if(word[i] == word[i-1]) {
//                 count++;
//             } else {
//                 freq.push_back(count);
//                 count = 1;
//             }
//         }
//         freq.push_back(count);

//         long long P = 1; //total possible strings
//         for(int &f : freq) {
//             P = (P * f) % M;
//         }
        
//         if(freq.size() >= k) {
//             return P;
//         }
//         int n = freq.size();
//         t.assign(n+1, vector<int>(k+1, -1)); //invalid krne k lie count should be less than k < k
//         //We have to now find count of invalid strings 
//         long long invalidCount = solve(0, 0, freq, k);

//         return (P - invalidCount + M) % M;


//     }
// };




class Solution {
public:
    int possibleStringCount(string word, int k) {
        int n = word.size(), cnt = 1;
        vector<int> freq;
        for (int i = 1; i < n; ++i) {
            if (word[i] == word[i - 1]) {
                ++cnt;
            } else {
                freq.push_back(cnt);
                cnt = 1;
            }
        }
        freq.push_back(cnt);

        int ans = 1;
        for (int o : freq) {
            ans = static_cast<long long>(ans) * o % mod;
        }

        if (freq.size() >= k) {
            return ans;
        }

        vector<int> f(k), g(k, 1);
        f[0] = 1;
        for (int i = 0; i < freq.size(); ++i) {
            vector<int> f_new(k);
            for (int j = 1; j < k; ++j) {
                f_new[j] = g[j - 1];
                if (j - freq[i] - 1 >= 0) {
                    f_new[j] = (f_new[j] - g[j - freq[i] - 1] + mod) % mod;
                }
            }
            vector<int> g_new(k);
            g_new[0] = f_new[0];
            for (int j = 1; j < k; ++j) {
                g_new[j] = (g_new[j - 1] + f_new[j]) % mod;
            }
            f = move(f_new);
            g = move(g_new);
        }
        return (ans - g[k - 1] + mod) % mod;
    }

private:
    static const int mod = 1000000007;
};