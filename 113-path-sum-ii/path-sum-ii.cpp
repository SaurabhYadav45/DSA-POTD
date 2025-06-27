/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     void solve(TreeNode* root, int targetSum, int sum, vector<int>temp, vector<vector<int>>&ans){
//         // Base case
//         if(root == NULL) return;
//         sum += root->val;
//         temp.push_back(root->val);
//         if(root->left == NULL && root->right == NULL){
//             if(sum == targetSum){
//                 ans.push_back(temp);
//             }
//             else
//                 return;
//         }
//         solve(root->left, targetSum, sum, temp, ans);
//         solve(root->right, targetSum, sum, temp, ans);
//     }
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//         vector<vector<int>>ans;
//         vector<int>temp;
//         int sum = 0;
//         solve(root, targetSum, sum, temp, ans);
//         return ans;    
//     }
// };





class Solution {
public:
    void solve(TreeNode* root, int targetSum, int sum, vector<int>temp,vector<vector<int>>&result){
        if(root == NULL) return;

        sum += root->val;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                result.push_back(temp);
                return;
            }
        }

        solve(root->left, targetSum, sum, temp, result);
        solve(root->right, targetSum, sum, temp, result);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return {};
        vector<vector<int>>result;
        vector<int>temp;
        solve(root, targetSum, 0, temp, result);
        return result;
    }
};