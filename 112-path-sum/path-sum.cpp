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
//     bool solve(TreeNode* root, int targetSum, int sum){
//         // Base case
//         if(root == NULL) return false;
//         sum += root->val;
//         if(root->left == NULL && root->right == NULL){
//             // Currently I'm at leaf node
//             if(sum  == targetSum){
//                 return true;
//             }
//             else
//                 return false;
//         }

//         bool leftAns = solve(root->left, targetSum, sum);
//         bool rightAns = solve(root->right, targetSum, sum);
//         return leftAns|| rightAns;
//     }
//     bool hasPathSum(TreeNode* root, int targetSum) {
//        int sum = 0;
//        bool ans = solve(root, targetSum, sum);
//        return ans; 
//     }
// };






class Solution {
public:
    bool solve(TreeNode* root, int sum, int targetSum){
        if(root == NULL){
            return false;
        }

        sum += root->val;
        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum) 
                return true;
            else 
                return false;
        }
        bool left = solve(root->left, sum, targetSum);
        bool right = solve(root->right, sum,  targetSum);
        return left ||  right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
       return solve(root, 0, targetSum);
    }
};