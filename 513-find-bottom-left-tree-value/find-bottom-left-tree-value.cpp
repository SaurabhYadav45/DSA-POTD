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

//                  ***********Using  DFS *************

// class Solution {
// public:
//     void solve(TreeNode* root, int currCount, int& levelCnt, int& result){
//         if(root == NULL) return;
//         if(root->left == NULL && root->right == NULL){
//             if(currCount > levelCnt){
//                 result = root->val;
//                 levelCnt = currCount;
//                 return;
//             }
//         }
//         solve(root->left, currCount + 1, levelCnt, result);
//         solve(root->right, currCount + 1, levelCnt, result);
//     }
//     int findBottomLeftValue(TreeNode* root) {
//         if(root->left == NULL && root->right == NULL){
//             return root->val;
//         }
//         int result = 0;
//         int levelCnt = 0;
//         solve(root, 0, levelCnt, result);
//         return result;
//     }
// };





//                  ***********Using  BFS *************

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);

        TreeNode* node;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                node = q.front();
                q.pop();

                if(node->right){
                    q.push(node->right);
                }
                if(node->left){
                    q.push(node->left);
                }
            }
        }
        return node->val; 
    }
};
