class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        vector<long long>pSum(n, 0);
        pSum[n-1] = shifts[n-1];
        for(int i=n-2; i>=0; i--){
            pSum[i] = pSum[i+1] + shifts[i];
        }

        for(int i=0; i<n; i++){
            s[i] = (s[i] - 'a' + pSum[i]) % 26 + 'a';
        }
        return s;
    }
};