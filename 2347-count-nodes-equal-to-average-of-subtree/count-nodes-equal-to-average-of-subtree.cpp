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
    int result = 0;
    pair<int, int>solve(TreeNode* root, int nodeCount, int sum){
        if(root == NULL) return {0, 0};
        pair<int, int>left = solve(root->left, nodeCount, sum);
        pair<int, int>right = solve(root->right, nodeCount, sum);
        int leftCount = left.first;
        int leftSum = left.second;
        int rightCount = right.first;
        int rightSum = right.second;
        int n = leftCount + rightCount + 1;
        int currSum = leftSum + rightSum + root->val;
        if((currSum / n) == root->val){
            result++;
        }
        return {n, currSum};
    }
    int averageOfSubtree(TreeNode* root) {
        if(root->left == NULL && root->right == NULL){
            return 1;
        }
        solve(root, 0, 0);
        return result;
    }
};