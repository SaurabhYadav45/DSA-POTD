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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool even = true;

        while(!q.empty()){
            int size = q.size();
            int prev;
            if(even == true){
                prev = INT_MIN;
            }
            else{
                prev = INT_MAX;
            }
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(even){
                    if(node->val % 2 == 0 || prev >= node->val){
                        return false;
                    }
                }
                else{
                    if(node->val % 2 != 0 || prev <= node->val){
                        return false;
                    }
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                prev = node->val;
            }
            even = !even;
        }
        return true;
    }
};