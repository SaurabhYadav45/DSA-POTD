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


//                           Using BFS

class Solution {
public:
    void rightSideViewFunction(TreeNode* root, vector<int>&ans){
        if(root == NULL) return ;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size  = q.size();
            TreeNode* node = NULL;
            while(size--){
                node = q.front();
                q.pop();
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            ans.push_back(node->val);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        rightSideViewFunction(root, ans);
        return ans;
    }
};



// class Solution {
// public:
//     void rightSideViewFunction(TreeNode* root, int level, vector<int>&ans){
//         if(root == NULL) return ;

//         if(level == ans.size()){
//             ans.push_back(root->val);
//         }
//         rightSideViewFunction(root->right, level+1, ans);
//         rightSideViewFunction(root->left, level+1, ans);
//     }
//     vector<int> rightSideView(TreeNode* root) {
//         int level = 0;
//         vector<int>ans;
//         rightSideViewFunction(root, level, ans);
//         return ans;
//     }
// };