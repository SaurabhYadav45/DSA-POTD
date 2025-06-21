// class Solution {
// public:

//     void permuteHelper(vector<int>& nums, vector<vector<int>>&ans, int start){
//         // Base case
//         if(start >= nums.size()){
//             ans.push_back(nums);
//             return;
//         }

//         for(int i=start; i<nums.size(); i++){
//             swap(nums[i], nums[start]);
//             permuteHelper(nums, ans, start+1);
//             // backtracking
//             swap(nums[i], nums[start]);
//         }
//     }

//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>>ans;
//         permuteHelper(nums, ans, 0);
//         return ans;
//     }
// };


class Solution {
public:
    vector<vector<int>>result;
    int n;

    void solve(vector<int>&nums, vector<int>curr, unordered_set<int>st){
        if(curr.size() == n){
            result.push_back(curr);
            return;
        }

        for(int i=0; i<n; i++){
            if(st.find(nums[i]) == st.end()){
                curr.push_back(nums[i]);
                st.insert(nums[i]);
                solve(nums, curr, st);
                // backtracking
                curr.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int>curr;
        unordered_set<int>st;
        solve(nums, curr, st);
        return result;
    }
};