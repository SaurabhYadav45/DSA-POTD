class Solution {
public:
    int n;
    int min_unfairness = INT_MAX;
    void solve(int idx, vector<int>& cookies, int k, vector<int>&curr){
        if(idx == n){
            int max_unfairness = *max_element(curr.begin(), curr.end());
            min_unfairness = min(min_unfairness, max_unfairness);
            return;
        }

        for(int i=0; i<k; i++){
            curr[i] += cookies[idx];
            solve(idx+1, cookies, k, curr);
            curr[i] -= cookies[idx];  // Backtrack;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        vector<int>curr(k);
        solve(0, cookies, k, curr);
        return min_unfairness;
    }
};