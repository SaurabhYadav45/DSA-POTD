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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& idx, int start, int end){
        if(start > end){
            return NULL;
        }
        int val = postorder[idx];
        int i = start;
        for(; i <=end; i++){
            if(val == inorder[i]){
                break;
            }
        }
        idx--;
        TreeNode*root = new TreeNode(val);
        root->right = solve(inorder, postorder, idx, i+1, end);
        root->left = solve(inorder, postorder, idx, start, i-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int start = 0;
        int end = n-1;
        int idx = n-1;
        TreeNode* root = solve(inorder, postorder, idx, start, end);
        return root;
        // if(root){
        //     return root;
        // }
        // return NULL;
    }
};







// class Solution {
// public:
//     void createMapping(vector<int>&inorder, int size, map<int, int>&mp){
//         for(int i=0; i<size; i++){
//             int element = inorder[i];
//             int index = i;
//             mp[element] = index;
//         }
//     }

//     TreeNode* constructTreeFromPostorderAndInorder(vector<int>& inorder, vector<int>& postorder, int&postIndex, int inorderStart, int inorderEnd, int size, map<int, int>&mp){
//         // Base case
//         if(postIndex < 0 || inorderStart > inorderEnd){
//             return NULL;
//         }
//         int element = postorder[postIndex];
//         postIndex--;
//         TreeNode* root = new TreeNode(element);
//         int position  = mp[element];

//         root->right = constructTreeFromPostorderAndInorder(inorder, postorder, postIndex, position+1, inorderEnd, size, mp);

//         root->left = constructTreeFromPostorderAndInorder(inorder, postorder, postIndex, inorderStart, position-1, size, mp);
//         return root;
//     }
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         int size = postorder.size();
//         int postIndex = size-1;
//         int inorderStart = 0;
//         int inorderEnd  = size-1;
//         map<int, int>mp;
//         createMapping(inorder, size, mp);
//         TreeNode* root = constructTreeFromPostorderAndInorder(inorder, postorder, postIndex, inorderStart, inorderEnd, size, mp);
//         return root;
//     }
// };