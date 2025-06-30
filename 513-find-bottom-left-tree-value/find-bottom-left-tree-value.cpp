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
//     int findLevel(TreeNode* root){
//         if(root == NULL) return 0;
//         int l = findLevel(root->left);
//         int r = findLevel(root->right);
//         return max(l, r) +1;
//     }
//     int findBottomLeftValue(TreeNode* root) {
//         int level = findLevel(root);
//         int result = 0;
//         queue<TreeNode*>q;
//         q.push(root);
//         int count = 1;
//         while(!q.empty()){
//             int size = q.size();
//             if(count == level){
//                 result = q.front()->val;
//                 break;
//             }
//             while(size--){
//                 TreeNode* node = q.front();
//                 q.pop();

//                 if(node->left){
//                     q.push(node->left);
//                 }
//                 if(node->right){
//                     q.push(node->right);
//                 }
//             }
//             count++;
//         }
//         return result; 
//     }
// };



class Solution {
public:
    void solve(TreeNode* root, int currCount, int& levelCnt, int& result){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            if(currCount > levelCnt){
                result = root->val;
                levelCnt = currCount;
                return;
            }
        }
        solve(root->left, currCount + 1, levelCnt, result);
        solve(root->right, currCount + 1, levelCnt, result);
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root->left == NULL && root->right == NULL){
            return root->val;
        }
        int result = 0;
        int levelCnt = 0;
        solve(root, 0, levelCnt, result);
        return result;
    }
};