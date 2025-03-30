class Solution {
public:

    int longestPalindromeSubstr(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (s[i] != s[j]) return INT_MIN;
        if (i == j) return 1;
        
        if (dp[i][j] != -1) return dp[j][i];
        
        return dp[i][j] = 2 + longestPalindromeSubstr(s, i + 1, j - 1, dp);
    }

    int lcs(string& s,string& t,int i,int j,vector<vector<int>>& dp){
        int n = s.size(),m=t.size();
        if(i>=n || j>=m)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == t[j])
            return dp[i][j] = 1+lcs(s,t,i+1,j+1,dp);

        return dp[i][j] = 0;
    }

    int computeMaxPalinFromLen(string&s,vector<vector<int>>&dp,vector<int>&maxS){
        int n = s.size(),ans = 0;
        for(int i=0;i<n;i++){
            int mx = 1;
            for(int j=n-1;j>=i;j--){
                longestPalindromeSubstr(s,i,j,dp);
                mx = max(mx,dp[i][j]);
            }
            maxS[i] = mx;
            ans=max(ans,mx);
        }
        return ans;
    }


    int longestPalindrome(string s, string t) {
        reverse(t.begin(),t.end());
        int n = s.size(),m=t.size(),ans = 1;

        vector<int>maxS(n,1);
        vector<int>maxT(m,1);
        vector<vector<int>>lcs_dp(n,vector<int>(m,-1));
        vector<vector<int>>dp(n,vector<int>(n,-1));
        vector<vector<int>>dp1(m,vector<int>(m,-1));
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                lcs(s,t,i,j,lcs_dp);
            }
        }

        ans=max(ans,computeMaxPalinFromLen(s,dp,maxS));
        ans=max(ans,computeMaxPalinFromLen(t,dp1,maxT));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int lcs_len = 2*lcs_dp[i][j];
                int idx_nxt_s = i+lcs_dp[i][j];
                int idx_nxt_t = j+lcs_dp[i][j];

                // either pick max-palindrome substr from i+1 onwards from s or j+1 onwards from t.
                int fromT = idx_nxt_t<m?maxT[idx_nxt_t]:0;
                int fromS = idx_nxt_s<n?maxS[idx_nxt_s]:0;

                ans = max(ans,lcs_len+fromT);
                ans = max(ans,lcs_len+fromS);
            }
        }

        return ans;
    }
};