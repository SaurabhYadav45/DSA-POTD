class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>dp(n, 1);
        vector<int>prev(n, -1);

        int maxL = 1;
        int lastIdx = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[i] < dp[j]+1){
                        dp[i] = max(dp[i], dp[j]+1);
                        prev[i] = j;
                    }

                    if(maxL < dp[i]){
                        maxL = dp[i];
                        lastIdx = i;
                    }
                }
            }
        }

        vector<int>result;
        while(lastIdx >= 0){
            result.push_back(nums[lastIdx]);
            lastIdx = prev[lastIdx];
        }
        return result;
    }
};


//            ********* Recursion : TLE **************

// class Solution {
// public:
//     vector<int>result;
//     void solve(int i, int prev, vector<int>& nums, vector<int>&curr){
//         if(i >= nums.size()){
//             if(curr.size() > result.size()){
//                 result = curr;
//             }
//             return;
//         }
//         // take
//         if(prev == -1|| nums[i] % nums[prev] == 0){
//             curr.push_back(nums[i]);
//             solve(i+1, i, nums, curr);
//             curr.pop_back();
//         }
//         // skip
//         solve(i+1, prev, nums, curr);
//     }
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         vector<int>curr;
//         solve(0, -1,  nums, curr);
//         return result;
//     }
// };