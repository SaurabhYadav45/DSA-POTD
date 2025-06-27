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
    void solve(TreeNode* root, vector<int>&nums){
        if(root ==  NULL) return ;
        if(root->left == NULL && root->right == NULL){
            nums.push_back(root->val);
        }
        solve(root->left, nums);
        solve(root->right, nums);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>nums1;
        vector<int>nums2;
        solve(root1, nums1);
        solve(root2, nums2);
        if(nums1 == nums2) return true;
        return false;
    }
};