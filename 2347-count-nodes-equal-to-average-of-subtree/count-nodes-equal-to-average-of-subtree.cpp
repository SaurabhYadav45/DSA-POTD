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
    pair<int, int>solve(TreeNode* root, int nodeCount, int sum, int& result){
        if(root == NULL) return {0, 0};
        pair<int, int>left = solve(root->left, nodeCount, sum, result);
        pair<int, int>right = solve(root->right, nodeCount, sum, result);
    
        int n = left.first + right.first + 1;
        int currSum = left.second + right.second + root->val;
        if((currSum / n) == root->val){
            result++;
        }
        return {n, currSum};
    }
    int averageOfSubtree(TreeNode* root) {
        if(root->left == NULL && root->right == NULL){
            return 1;
        }
        int result = 0;
        solve(root, 0, 0, result);
        return result;
    }
};