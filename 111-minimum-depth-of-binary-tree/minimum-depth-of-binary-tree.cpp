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
//     void findDepth(TreeNode*root, int count, int&result){
//         if(root == NULL) return;
//         if(root->left == NULL && root->right == NULL){
//             result = min(result, count);
//         }
//         findDepth(root->left, count+1, result);
//         findDepth(root->right, count+1, result);
//     }
//     int minDepth(TreeNode* root) {
//         if(root == NULL) return 0;
//         int result = INT_MAX;
//         findDepth(root, 1, result);
//         return result;
//     }
// };



class Solution {
public:
    int findDepth(TreeNode*root){
        if(root == NULL) return 0;

        int l = findDepth(root->left);
        int r = findDepth(root->right);
        if(root->left == NULL || root->right == NULL){
            return max(l, r) +1;
        }
        return min(l, r)+1;
    }
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return findDepth(root);
    }
};