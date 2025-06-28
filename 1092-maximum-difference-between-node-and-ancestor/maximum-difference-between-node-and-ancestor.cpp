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
    int maxDiff = -1;
    void findMaxDifference(TreeNode* root, TreeNode* child){
        if(child == NULL) return;
        maxDiff = max(maxDiff, abs(root->val - child->val));

        findMaxDifference(root, child->left);
        findMaxDifference(root, child->right);
    }
    void solve(TreeNode*root){
        if(root == NULL) return;
        findMaxDifference(root, root->left);
        findMaxDifference(root, root->right);
        solve(root->left);
        solve(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root);
        return maxDiff;
    }
};