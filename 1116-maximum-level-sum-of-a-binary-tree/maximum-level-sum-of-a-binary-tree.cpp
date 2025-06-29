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
    int maxLevelSum(TreeNode* root) {
        int result  = 0;
        queue<TreeNode*>q;
        q.push(root);
        int level = 1;
        int maxSum = INT_MIN;
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(sum > maxSum){
                maxSum = sum;
                result = level;
            }
            level++;
        }
        return result;
    }
};









// class Solution {
// public:
//     int maxLevelSum(TreeNode* root) {
//         queue<TreeNode*>q;
//         q.push(root);
//         int count = 1;
//         int maxSum = INT_MIN;
//         int level = 0;

//         while(!q.empty()){
//             int size = q.size();
//             int sum = 0;

//             for(int i=0; i<size; i++){
//                 TreeNode* front = q.front();
//                 q.pop();

//                 sum += front->val;

//                 if(front->left != NULL){
//                     q.push(front->left);
//                 }

//                 if(front->right != NULL){
//                     q.push(front->right);
//                 }
//             }

//             if(sum > maxSum){
//                 maxSum = sum;
//                 level = count;
//             }
//             count++;
//         }
//         return level;
//     }
// };



