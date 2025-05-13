class Solution {
public:
    const int MOD = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        int n = s.length();
        vector<int>count(26);

        for(char&ch : s){
            count[ch - 'a']++;
        }

        for(int i=0; i<t; i++){
            int zCount = count[25];
            for(int j=25; j>1; j--){
                count[j] = count[j-1];
            }

            count[1] = (count[0] + zCount)% MOD;
            count[0] = zCount;
        }

        long long result = 0;
        for(auto& c : count){
            result += c;
        }

        return result % MOD;
    }
};