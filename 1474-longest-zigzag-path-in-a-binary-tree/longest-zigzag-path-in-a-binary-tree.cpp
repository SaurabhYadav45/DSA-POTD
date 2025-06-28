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
    int maxPath = -1;
    void findLongesZingZaga(TreeNode*root, int left, int right){
        if(root == NULL) return;

        maxPath = max({maxPath, left, right});
        findLongesZingZaga(root->left, right+1, 0);
        findLongesZingZaga(root->right, 0, left+1);
    }
    int longestZigZag(TreeNode* root) {
        findLongesZingZaga(root, 0, 0);
        return maxPath;
    }
};