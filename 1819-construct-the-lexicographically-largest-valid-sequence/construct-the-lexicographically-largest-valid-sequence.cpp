class Solution {
public:
    bool solve(int i, int n, vector<bool>&used, vector<int>&result){
        if(i >= result.size()){
            return true;
        }

        if(result[i] != -1){
            return solve(i+1, n, used, result);
        }

        for(int num=n; num>=1; num--){
            if(used[num] == true) continue;

            used[num] = true;
            result[i] = num;
            if(num == 1){
                if(solve(i+1, n, used, result)){
                    return true;
                }
            }
            else{
                int j = i + num;
                if(j < result.size() && result[j] == -1){
                    result[j] = num;
                    if(solve(i+1, n, used, result)){
                        return true;
                    }
                    result[j] = -1;
                }
            }
            // Backtrack
            used[num] = false;
            result[i] = -1;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<bool>used(n+1, false);
        vector<int>result(2*n-1, -1);
        solve(0, n, used, result);
        return result;
    }
};




// class Solution {
// public:
//     solve(int n, vector<int>&freq, unordered_set<int>&st, vector<int>&result){
//         if(result.size() == 2*n-1){
//             return;
//         }

//         for(int i=n; i>=1; i++){
//             if(freq[i] > 0 && result.back() != i){
//                 result.push_back(i);
//                 freq[i]--;

//                 if(freq[i] == 0 && i != 1){

//                 }
//             }
//         }
//     }
//     vector<int> constructDistancedSequence(int n) {
//         unordered_set<int>st;
//         vector<int>freq(n+1, 0);
//         for(int i=1; i<=n; i++){
//             if(i == 1){
//                 freq[i]++;
//             }
//             else{
//                 freq[i] += 2;
//             }
//         }
//         vector<int>result;
//         solve(n, freq, st, result);
//     }
// };