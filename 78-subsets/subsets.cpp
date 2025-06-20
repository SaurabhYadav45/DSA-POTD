// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>>result;
//         for(int i=0; i<(1<<n); i++){
//             vector<int>subset;
//             for(int j=0; j<n; j++){
//                 if((1<<j) & i){
//                     subset.push_back(nums[j]);
//                 }
//             }
//             result.push_back(subset);
//         }
//         return result;
//     }
// };



class Solution {
public:
    void solve(int i, vector<int>&nums, vector<int>curr, vector<vector<int>>&result){
        if(i >= nums.size()){
            result.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        solve(i+1, nums, curr, result);
        curr.pop_back();

        solve(i+1, nums, curr, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        solve(0, nums, {}, result);
        return result;
    }
};



// class Solution {
// public:

//     //  T.C = 2^n
//     // S.C = O(n)
//     // Stacl space = O(n)

//     void subsetFinder(vector<int>& nums, vector<vector<int>>&ans, vector<int>&path , int i){
//         // Base Case
//         if(i >= nums.size()){
//             ans.push_back(path);
//             return;
//         }
//         // Exclude
//         subsetFinder(nums, ans, path, i+1);
//         // Include
//         path.push_back(nums[i]);
//         subsetFinder(nums, ans, path, i+1);
//         path.pop_back();
//     }
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>>ans;
//         vector<int>path;
//         subsetFinder(nums, ans, path, 0);
//         return ans;
//     }
// };
