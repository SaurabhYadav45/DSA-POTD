class Solution {
public:
    vector<vector<int>>result;
    void solve(int n, int k, vector<int>&curr, int idx){
        if(curr.size() == k){
            result.push_back(curr);
            return;
        }
        if(idx >= n+1){
            return;
        }

        for(int i=idx; i<=n; i++){
            curr.push_back(i);
            solve(n, k, curr, i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>curr;
        solve(n, k, curr, 1);
        return result;
    }
};