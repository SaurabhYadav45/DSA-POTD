class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.length();
        vector<long long>prefix(n, 0);
        vector<long long>suffix(n, 0);

        // fill the prefix array
        if(s[0] == 'L') prefix[0] = 1;
        for(int i=1; i<n; i++){
            if(s[i] == 'L'){
                prefix[i] = prefix[i-1] + 1;
            }
            else{
                prefix[i] = prefix[i-1];
            }
        }

        // fill the suffix array
        if(s[n-1] == 'T') suffix[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            if(s[i] == 'T'){
                suffix[i] = suffix[i+1] + 1;
            }
            else{
                suffix[i] = suffix[i+1];
            }
        }

        // Now calculate the maximum number of LCT for each c
        long long case1 = 0;
        long long case2 = 0;
        long long case3 = 0;
        long long maxi = -1;
        for(int i=0; i<n; i++){
            if(s[i] == 'C'){
                // If we insert L at beginning
                case1 += (prefix[i]+1) * suffix[i];
                // If we insert R at ending
                case2 += prefix[i] * (suffix[i]+1);
                // Without insertion
                case3 += prefix[i] * suffix[i];
            }
            maxi = max(maxi, prefix[i] * suffix[i]);
        }
        case3 += maxi;

        return max({case1, case2, case3});
    }
};