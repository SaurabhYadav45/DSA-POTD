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
//     int countNodes(TreeNode* root) {
//         if(root == NULL) return 0;
//         int left = countNodes(root->left);
//         int right = countNodes(root->right);
//         return left + right + 1;
//     }
// };



// Optimized

class Solution {
public:
    int countLeftHeight(TreeNode* root){
        TreeNode* temp = root;
        int lh = 0;
        while(temp != NULL){
           lh++;
           temp = temp->left; 
        }
        return lh;
    }
    int countRightHeight(TreeNode* root){
        TreeNode* temp = root;
        int rh = 0;
        while(temp != NULL){
           rh++;
           temp = temp->right; 
        }
        return rh;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = countLeftHeight(root);
        int rh = countRightHeight(root);
        if(lh == rh){
            // Perfect Binary tree
            return pow(2, lh)-1;
        }

        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return left + right + 1;
    }
};