class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();

        for(int i=1; i<n; i++){
            if(complexity[0] >= complexity[i]) return 0;
        }

        long long result = 1;
        for(int i=2; i<n; i++){
            result = result*i % MOD;
        }
        return result;
    }
};