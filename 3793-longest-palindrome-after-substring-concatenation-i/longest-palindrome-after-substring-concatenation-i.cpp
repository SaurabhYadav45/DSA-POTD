class Solution {
public:
    bool isPalindrome(string joined){
        int n = joined.length();
        int i=0;
        int j = n-1;
        while(i<=j){
            if(joined[i] != joined[j]) return false;

            i++;
            j--;
        }
        return true;
    }
    int longestPalindrome(string s, string t) {
        int m = s.length();
        int n = t.length();

        int maxLength = 1;

        for(int i=0; i<=m; i++){
            for(int j=i; j<=m; j++){
                string s_str = s.substr(i, j-i);

                for(int k=0; k<=n; k++){
                    for(int l=k; l<=n; l++){
                        string t_str = t.substr(k, l-k);

                        string joined = s_str + t_str;
                        if(isPalindrome(joined)){
                            maxLength = max(maxLength, (int)joined.size());
                        }

                    }
                }
            }
        }
        return maxLength;
    }
};
