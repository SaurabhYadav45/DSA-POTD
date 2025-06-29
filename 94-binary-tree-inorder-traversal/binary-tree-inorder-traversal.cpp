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
    // void inorder(TreeNode*root, vector<int>&ans){
    //     if(root ==  NULL) return;
    //     inorder(root->left,ans);
    //     ans.push_back(root->val);
    //     inorder(root->right, ans);
    // }

    // MORRIS TRAVERSAL

//     vector<int> morrisTraversal(TreeNode*root){
//         vector<int>ans;
//         TreeNode*curr = root;
//         while(curr){
//             if(curr->left == NULL){
//                 ans.push_back(curr->val);
//                 curr = curr->right;
//             }
//             else{
//                 TreeNode* pred = curr->left;
//                 while(pred->right != curr && pred->right){
//                     pred = pred->right;
//                 }

//                 if(pred->right == NULL){
//                     pred->right = curr;
//                     curr = curr->left;
//                 }
//                 else{
//                     pred->right = NULL;
//                     ans.push_back(curr->val);
//                     curr = curr->right;
//                 }
//             }
//         }
//         return ans;
//     }

//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         // inorder(root, ans);
//         ans = morrisTraversal(root);
//         return ans;
//     }
// };



class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
        TreeNode*curr = root;
        TreeNode*prev ;
        while(curr!= NULL){
            if(curr->left == NULL){
                result.push_back(curr->val);
                curr = curr->right;
            }
            else{
                // curr->left !=  NULL
                prev = curr->left;
                while(prev->right !=  NULL){
                    prev = prev->right;
                }
                prev->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
        }
        return result;
    }
};