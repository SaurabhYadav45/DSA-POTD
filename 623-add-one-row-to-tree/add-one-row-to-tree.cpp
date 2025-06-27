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
    TreeNode* solve(TreeNode* root, int val, int depth, int d){
        if(root == NULL) return NULL;

        d++;
        if(depth == d){
            TreeNode*L = new TreeNode(val);
            TreeNode*R = new TreeNode(val);
            L->left = root->left;
            L->right = NULL;
            R->right = root->right;
            R->left = NULL;
            root->left = L;
            root->right = R;
            return root;
        }

        root->left = solve(root->left, val, depth, d);
        root->right = solve(root->right, val, depth, d);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        return solve(root, val, depth, 1);
    }
};