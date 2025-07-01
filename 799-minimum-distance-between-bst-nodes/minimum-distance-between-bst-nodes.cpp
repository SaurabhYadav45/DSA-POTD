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
//     TreeNode* prev;
//     int minDiffInBST(TreeNode* root) {
//         if(root == NULL) return INT_MAX;

//         int ans = INT_MAX;
//         int left = minDiffInBST(root->left);
//         ans = min(ans, left);

//         if(prev != NULL){
//             ans = min(ans, root->val - prev->val);
//         }
//         prev = root;

//         int right = minDiffInBST(root->right);
//         ans = min(ans, right);

//         return ans;
//     }
// };



class Solution {
public:
    TreeNode* prev;
    int ans = INT_MAX;
    void solve(TreeNode* root){
        if(root == NULL) return;
        
        solve(root->left);

        if(prev != NULL){
            ans = min(ans, root->val - prev->val);
        }
        prev = root;

        solve(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};