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

class Solution {
public:
    long long maximumProduct;
    const int MOD = 1e9 + 7;
    long long calculateTotalSum(TreeNode*root){
        if(root == NULL) return 0;
        long long l = calculateTotalSum(root->left);
        long long r = calculateTotalSum(root->right);
        return l + r + root->val;
    }
    long long solve(TreeNode*root, long long totalSum){
        if(root == NULL) return 0;
        long long left = solve(root->left, totalSum);
        long long right = solve(root->right, totalSum);
        long long sum = left + right + root->val;
        maximumProduct = max(maximumProduct, sum*(totalSum-sum));
        return sum;
    }
    int maxProduct(TreeNode* root) {
        long long totalSum = 0;
        maximumProduct = -1;
        totalSum = calculateTotalSum(root);
        solve(root, totalSum);
        return maximumProduct % MOD;
    }
};




// class Solution {
// public:
//     long long maximumProduct;
//     const int MOD = 1e9 + 7;
//     long long calculateTotalSum(TreeNode*root){
//         if(root == NULL) return 0;
//         long long l = calculateTotalSum(root->left);
//         long long r = calculateTotalSum(root->right);
//         return l + r + root->val;
//     }
//     void solve(TreeNode*root, long long totalSum){
//         if(root == NULL) return;
//         long long leftSubtreeSum = calculateTotalSum(root->left);
//         long long rightSubtreeSum = calculateTotalSum(root->right);
//         long long leftSum = (leftSubtreeSum)*(totalSum-leftSubtreeSum);
//         long long rightSum = (rightSubtreeSum)*(totalSum-rightSubtreeSum);
//         maximumProduct = max(maximumProduct, max(leftSum, rightSum)) % MOD;
//         solve(root->left, totalSum);
//         solve(root->right, totalSum);
//     }
//     int maxProduct(TreeNode* root) {
//         long long totalSum = 0;
//         maximumProduct = -1;
//         totalSum = calculateTotalSum(root);
//         solve(root, totalSum);
//         return maximumProduct;
//     }
// };

