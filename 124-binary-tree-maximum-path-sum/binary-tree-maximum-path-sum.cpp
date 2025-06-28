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
    int maximumSum(TreeNode* root, int& maxSum){
        if(root == NULL) return 0;

        int left = maximumSum(root->left, maxSum);
        int right = maximumSum(root->right, maxSum);

        int valueSum = root->val;
        int leftChildSum = root->val + left;
        int rightChildSum = root->val + right;
        int leftAndRightChildSum = left + right + root->val;

        maxSum = max({maxSum, valueSum, leftChildSum, rightChildSum, leftAndRightChildSum});
        return  max({valueSum, leftChildSum, rightChildSum});
    }
    int maxPathSum(TreeNode* root) {
        if(!root->left && !root->right) return root->val;
        int maxSum = INT_MIN;
        maximumSum(root, maxSum);
        return maxSum;
    }
};