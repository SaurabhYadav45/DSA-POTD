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
    vector<int> caculateRowSum(TreeNode*root){
        vector<int>pSum;
        queue<TreeNode*>q;
        q.push(root);
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
            pSum.push_back(sum);
        }
        return pSum;
    }

    int solve(TreeNode*&root, int level, vector<int>&pSum){
        if(root == NULL) return 0;

        int l =solve(root->left, level+1, pSum);
        int r = solve(root->right, level+1, pSum);

        int currSum = l + r;
        if(root->left){
            root->left->val = pSum[level]-currSum;
        }
        if(root->right){
            root->right->val = pSum[level]-currSum;
        }
        return root->val;
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int>pSum = caculateRowSum(root);
        solve(root, 1, pSum);
        root->val = 0;
        return root;
    }
};