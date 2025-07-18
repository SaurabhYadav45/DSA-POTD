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



//           *************** MORRIS TRAVERSAL *****************

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
        TreeNode*curr = root;

        while(curr!= NULL){
            if(curr->left == NULL){
                result.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode*pre = curr->left;
                while(pre->right !=  NULL){
                    pre = pre->right;
                }
                pre->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
        }
        return result;
    }
};