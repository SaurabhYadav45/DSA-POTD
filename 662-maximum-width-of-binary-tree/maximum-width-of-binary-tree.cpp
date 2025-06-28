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
    void findWidth(TreeNode*root, int& maxWidth){
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            int startIdx = q.front().second;
            int lastIdx = q.back().second;
            maxWidth = max(maxWidth, lastIdx-startIdx + 1);
            while(size--){
                TreeNode* node = q.front().first;
                int i = q.front().second;
                q.pop();
                
                if(node->left){
                    q.push({node->left, (long)2*i+1});
                }
                if(node->right){
                    q.push({node->right, (long)2*i+2});
                }
            }
        }
    }
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = -1;
        findWidth(root, maxWidth);
        return maxWidth;
    }
};